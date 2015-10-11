#pragma once
#include "Point.h"

class Point2d: public Point{
public:
	Point2d(int _x , int _y):Point(2){
		v[0] = _x;
		v[1] = _y;
	}

	virtual Point NullPoint() override{
		return Point2d(0, 0);
	}
};