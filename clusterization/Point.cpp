#include "Point.h"

Point::Point(){
	dim = 0;
}
Point::Point(int _dim){
	dim = _dim;
	v = new int[dim];
}
Point::Point(const Point & _p) {
	dim = _p.getDimension();
	v = new int[dim];
	for (int i = 0; i < dim; i++)
		v[i] = _p.getÑordinate(i);
}

bool Point::isEqual(Point _p){// ñðàâíåíèå 2õ òî÷åê
	for (int i = 0; i < dim; i++)
		if (v[i] != _p.getÑordinate(i))
			return false;
	return true;
}
double Point::evcMetric(Point _p1, Point _p2){
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += pow(_p1.getÑordinate(i) - _p2.getÑordinate(i), 2);
	return sqrt(sum);
};
int Point::manhattanMetric(Point _p){
	int sum = 0;
	for (int i = 0; i < dim; i++)
		sum += abs(v[i] - _p.getÑordinate(i));
	return sum;
}
Point& Point::operator=(Point& _p){
	dim = _p.getDimension();
	delete[]v;
	v = new int[dim];
	for (int i = 0; i < dim; i++)
		v[i] = _p.getÑordinate(i);
	return *this;

}

//supply methods
void Point::logPoint(){
	for (int i = 0; i < dim; i++)
		cout << v[i] << " ";
	cout << endl;
}
Point Point::NullPoint(){
	return *this;
}