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
			clusters[i].setMedoid(pset[k*i]);//выбираем рандомные точки из множества как метроиды	
		}
		
	}

	void AssignCorrectMetroid(){
		for (auto it = pset.begin(); it != pset.end(); it++){
			for (int j = 0; j < numOfClusters; j++){
				it->manhattanMetric(*it, );
			}
		}
	}

	~cProcc(){
		delete clusters;
	}

};