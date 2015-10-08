#include <iostream>
#include <vector>
#include "Point2.h"
#include "Cluster.h"
using namespace std;
class cProcc{
	int numOfClusters;
	vector<Point2> pset;
	vector<Point2> metroids;
	Cluster* clusters;
public:
	cProcc(int _numOfClusters, vector<Point2> _data) : pset(_data), numOfClusters(_numOfClusters){
		clusters = new Cluster[_numOfClusters];
		RandSetMetroids();
	}
	void RandSetMetroids(){
		int k = pset.size() / numOfClusters;
		for (int i = 0; i < numOfClusters; i++){
			clusters[i].setMedoid(pset[k*i]);//�������� ��������� ����� �� ��������� ��� ��������	
		}
		
	}
	void Start(){
		bool status = false;
		do{
			AssignCorrectMetroid();
			for (int i = 0; i < numOfClusters; i++)
				status | clusters[i].updateCurrentMedoid();//���� ���� �� ���� ������� ������������� ������� ������������� ��������� ��������� ���� �����
		} while (status);
	}
	void AssignCorrectMetroid(){
		for (auto it = pset.begin(); it != pset.end(); it++){
			int min = 9999;//��������!!!
			int currClusterId = 0;
			for (int j = 0; j < numOfClusters; j++){
				int dis = it->manhattanMetric(clusters[j].getCurMedoid());//���������� ���������� � �������
				if (min > dis){
					min = dis;
					currClusterId = j;
				}
			}
			clusters[currClusterId].addPoint(*it);
		}
	}

	~cProcc(){
		delete clusters;
	}

};