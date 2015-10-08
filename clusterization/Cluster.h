#include <vector>
#include "Point2.h"

using namespace std;
class Cluster{
	vector<Point2> ps;
	Point2 curMedoid;
	Point2 prevMedoid;
public:
	Cluster():curMedoid(Point2(0,0)), prevMedoid(Point2(0,0)){}
	void addPoint(Point2 _p) { ps.push_back(_p); }
	void setMedoid(Point2 _p) { prevMedoid = curMedoid; curMedoid = _p; }
	bool updateCurrentMedoid(){// check ?????
		int minCost = 99999; // поменять !
		Point2 tmp(0, 0);
		for (int i = 0; i < ps.size(); i++){
			int cost = 0;
			
			for (int j = 0; j < ps.size(); i++){
				cost += ps[i].manhattanMetric(ps[j]);
			}

			if (minCost > cost){
				minCost = cost;
				tmp = ps[i];
			}

		}
			
		if (!curMedoid.isEqual(tmp)){
			setMedoid(tmp); return true;
		}
		else
			return false;
	}
	Point2 getCurMedoid() { return curMedoid; }
};