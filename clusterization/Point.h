#pragma once
#include <vector>
#include <cmath>

class Point {
protected:
	int dim;
	int * v;
	Point(int _dim){
		dim = _dim;
		v = new int[dim]; 
	}
public:
	int get—ordinate(int _d){ return v[_d]; }
	~Point(){
		delete[] v;
	}
	double evcMetric(Point p1, Point p2){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum += pow(p1.get—ordinate(i) - p2.get—ordinate(i),2);
		return sqrt(sum);
	};
	int manhattanMetric(Point p1, Point p2){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum = abs(p1.get—ordinate(i) - p2.get—ordinate(i));
		return sum;
	}
private:
	Point(){}
};