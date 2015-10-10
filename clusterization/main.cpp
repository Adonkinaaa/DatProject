#include <iostream>
#include <vector>
#include "cProcc.h"
using namespace std;

int main(){
	vector<Point> data;
	Point2d p1(100, 101);
	Point2d p2(100, 80);
	Point2d p3(1, 0);
	Point2d p4(3, 7);
	Point2d p5(1, 6);
	Point2d p6(3, -1);
	data.push_back(p1); data.push_back(p2); data.push_back(p3); data.push_back(p4); data.push_back(p5); data.push_back(p6);
	cProcc p (2,data);
	p.showCurMedoids();
	cout << endl;
	p.start();
	p.showCurMedoids();
	//c.getCurMedoid().show();
	system("pause");
	return 0;
}