#pragma once
#include <iostream>
#include "Point.h"

class Point2:public Point {
public:
	Point2(int x, int y): Point(2) 
	{ 
		v[0] = x; 
		v[1] = y; 
	}
	Point2(Point2 & _p) : Point(2){
		for (int i = 0; i < dim; i++)
			v[i] = _p.getÑordinate(i);
	}
};