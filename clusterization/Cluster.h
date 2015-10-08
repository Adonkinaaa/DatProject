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
};