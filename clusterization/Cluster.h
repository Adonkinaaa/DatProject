#include <vector>
#include "Point2d.h"

using namespace std;
class Cluster{
	vector<Point> ps;
	Point curMedoid;
	Point prevMedoid;
	Point origin;
public:
	Cluster(Point _origin) : origin(_origin){
		curMedoid = origin;
		prevMedoid = origin;
	}
	void clear() { ps.clear(); }//wtf?
	void addPoint(Point _p) { ps.push_back(_p); }
	void setMedoid(Point _p) { prevMedoid = curMedoid; curMedoid = _p; }
	int getClustrSize(){ return ps.size(); }
	Point getMedoid() { return curMedoid; }
	bool updateCurrentMedoid(){// check ?????
		int minCost = 99999; // поменять !
		Point tmp = origin.NullPoint();
		int s = ps.size();
		for (int i = 0; i < ps.size(); i++){
			int cost = 0;
			
			for (int j = 0; j < ps.size(); j++){
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
	Point getCurMedoid() { return curMedoid; }
};