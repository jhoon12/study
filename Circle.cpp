#include "Circle.h"
#include<iostream>
using namespace std;
Circle::Circle()
{
	cout << "���ھ��� Circle ������ ȣ��" << endl;
}

Circle::Circle(int X, int Y, int R)
{
	cout << "�����ִ� Circle ������ ȣ��" << endl;
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
	cout << "�߽���(" << this->x << "," << this->y << ")  /  ";
	cout << "������ : " << this->r << endl;
}

void Circle::areaCircle()
{
	cout << "���� : " << 3.14 * r * r<< endl;
}

Circle::~Circle()
{
	cout << "Circle �Ҹ��� ȣ��" << endl;
}

