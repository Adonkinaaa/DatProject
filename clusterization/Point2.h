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
};