#pragma once
#include"Point.h"
class Circle {
private:
	int x, y, r;
public:
	Point p1;
	Circle();
	Circle(int X, int Y, int R);
	void setCircle(int X, int Y, int R);
	void showCircle();
	void areaCircle();
	~Circle();




};