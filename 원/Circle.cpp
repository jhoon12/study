#include "Circle.h"
#include<iostream>
using namespace std;
Circle::Circle()
{
	cout << "인자없는 Circle 생성자 호출" << endl;
}

Circle::Circle(int X, int Y, int R)
{
	cout << "인자있는 Circle 생성자 호출" << endl;
	this->x = X;
	this->y = Y;
	this->r = R;
}

void Circle::setCircle(int X, int Y, int R)
{
	this->x = X;
	this->y = Y;
	this->r = R;
}

void Circle::showCircle()
{
	cout << "중심점(" << this->x << "," << this->y << ")  /  ";
	cout << "반지름 : " << this->r << endl;
}

void Circle::areaCircle()
{
	cout << "넓이 : " << 3.14 * r * r<< endl;
}

Circle::~Circle()
{
	cout << "Circle 소멸자 호출" << endl;
}

