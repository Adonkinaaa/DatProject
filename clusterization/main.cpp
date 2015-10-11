#include <iostream>
#include <vector>
#include "cProcc.h"
using namespace std;

int main(){
	vector<Point> data;
	Point2d p1(-1, -1);
	Point2d p4(-33, -22);
	Point2d p6(-5, -4);
	Point2d p8(1, 1);
	Point2d p7(4, 4);
	Point2d p5(3, 3);
	Point2d p3(7, 3);
	Point2d p2(6, 0);
	data.push_back(p1); data.push_back(p2); data.push_back(p3); data.push_back(p4); data.push_back(p5); data.push_back(p6); data.push_back(p7); data.push_back(p8);
	cProcc p (2,data);
	p.start();
	system("pause");
	return 0;
}