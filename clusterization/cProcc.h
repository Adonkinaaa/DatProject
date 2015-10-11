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

	cProcc(int _numOfClusters, vector<Point> _data);

	void RandSetMedoids();
	void start();
	void assignCorrectMetroid();
	void logCurMedoids();

	~cProcc(){
		for (int i = 0; i < numOfClusters; i++)
			delete clusters[i];
		delete[] clusters;
	}

};