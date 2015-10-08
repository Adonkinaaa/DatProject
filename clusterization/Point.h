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
	int get�ordinate(int _d){ return v[_d]; }

	bool isEqual(Point _p){// ��������� 2� �����
		for (int i = 0; i < dim; i++)
			if (v[i] != _p.get�ordinate(i))
				return false;
		return true;
	}
	double evcMetric(Point _p1, Point _p2){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum += pow(_p1.get�ordinate(i) - _p2.get�ordinate(i),2);
		return sqrt(sum);
	};
	int manhattanMetric(Point _p){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum = abs(v[i] - _p.get�ordinate(i));
		return sum;
	}
	Point& operator=(Point& _p){
		for (int i = 0; i < 2; i++)
			v[i] = _p.get�ordinate(i);
		return *this;
	}
	~Point(){
		delete[] v;
	}
private:
	Point(){}
};