#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Point {
protected:
	int dim;
	int * v;

public:

	Point();
	Point(int _dim);
	Point(const Point & _p);
	Point& operator=(Point& _p);
	~Point(){
		delete[] v;
	}

	bool isEqual(Point _p);
	double evcMetric(Point _p1, Point _p2);
	int manhattanMetric(Point _p);
	
	//supply methods

	int getCordinate(int _d)const{ return v[_d]; }
	int getDimension()const{ return dim; }
	void logPoint();
	virtual Point NullPoint();

};