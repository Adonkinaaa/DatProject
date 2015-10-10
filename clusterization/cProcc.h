#include <iostream>
#include <vector>
#include <iostream>
#include "Cluster.h"

using namespace std;
class cProcc{
	int numOfClusters;
	vector<Point> pset;
	vector<Point> metroids;
	Cluster** clusters;
public:
	cProcc(int _numOfClusters, vector<Point> _data) : pset(_data), numOfClusters(_numOfClusters){
		clusters = new Cluster*[_numOfClusters];
		for (int i = 0; i < _numOfClusters; i++)
			clusters[i] = new Cluster(_data[0].NullPoint());
		RandSetMetroids();
	}
	void RandSetMetroids(){
		int k = pset.size() / numOfClusters;
		for (int i = 0; i < numOfClusters; i++){
			clusters[i]->setMedoid(pset[k*i]);//выбираем рандомные точки из множества как метроиды	
		}
	}

	void start(){
		bool status = false;
		do{
			status = false;
			assignCorrectMetroid();
			for (int i = 0; i < numOfClusters; i++){
				status |= clusters[i]->updateCurrentMedoid();//если хотя бы одна функция центрирования вернула положительный результат повторяем цикл снова
				clusters[i]->getMedoid().show();
			}
				cout << endl;
		} while (status);
	}
	void assignCorrectMetroid(){
		for (int i = 0; i < numOfClusters; i++)
			clusters[i]->clear();
		for (auto it = pset.begin(); it != pset.end(); it++){
			int min = 9999;//поменять!!!
			int currClusterId = 0;
			for (int j = 0; j < numOfClusters; j++){
				int dis = it->manhattanMetric(clusters[j]->getCurMedoid());//сравниваем координаты с центром
				if (min > dis){
					min = dis;
					currClusterId = j;
				}
			}
			clusters[currClusterId]->addPoint(*it);
		}
		//for (int i = 0; i < numOfClusters; i++)
		//	cout << clusters[i]->getClustrSize() << " ";
		//cout << endl;
	}
	void showCurMedoids(){
		for (int i = 0; i < numOfClusters; i++)
			clusters[i]->getMedoid().show();
	}
	~cProcc(){
		delete [] clusters;
	}

};