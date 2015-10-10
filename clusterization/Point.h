#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Point {
protected:
	int dim;
	//int * v;

public:
	int * v;
	int get—ordinate(int _d)const{ return v[_d]; }
	int getDimension()const{ return dim; }
	Point(){
		dim = 0;
	}
	Point(int _dim){
		dim = _dim;
		v = new int[dim];
	}
	Point(const Point & _p) {
		dim = _p.getDimension();
		v = new int[dim];
		for (int i = 0; i < dim; i++)
			v[i] = _p.get—ordinate(i);
	}

	bool isEqual(Point _p){// Ò‡‚ÌÂÌËÂ 2ı ÚÓ˜ÂÍ
		for (int i = 0; i < dim; i++)
			if (v[i] != _p.get—ordinate(i))
				return false;
		return true;
	}
	double evcMetric(Point _p1, Point _p2){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum += pow(_p1.get—ordinate(i) - _p2.get—ordinate(i),2);
		return sqrt(sum);
	};
	int manhattanMetric(Point _p){
		int sum = 0;
		for (int i = 0; i < dim; i++)
			sum += abs(v[i] - _p.get—ordinate(i));
		return sum;
	}
	Point& operator=(Point& _p){
		dim = _p.getDimension();
		delete[]v;
		v = new int[dim];
		for (int i = 0; i < dim; i++)
			v[i] = _p.get—ordinate(i);
		return *this;
		
	}
	~Point(){
		delete[] v;
		//cout << " poin deleted" << endl;
	}
	//supply methods
	void show(){
		for (int i = 0; i < dim; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	virtual Point NullPoint(){
		return *this;
	}
};