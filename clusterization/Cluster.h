#include <vector>
#include "Point2d.h"

using namespace std;
class Cluster{
	vector<Point> ps;
	Point curMedoid;
	Point origin;
public:

	bool updateCurrentMedoid();

	Cluster(Point _origin);
	void clear() { ps.clear(); }
	void addPoint(Point _p) { ps.push_back(_p); }
	void setMedoid(Point _p) { curMedoid = _p; }
	int getClustrSize(){ return ps.size(); }
	Point getMedoid() { return curMedoid; }
	Point getCurMedoid() { return curMedoid; }

	void logCluster(){
		for (int i = 0; i < ps.size(); i++)
			ps[i].logPoint();
	}
};