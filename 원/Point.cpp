#include "Point.h"
#include<iostream>
using namespace std;

Point::Point()
{
	cout << "Point 인장없는 생성자 호출" << endl;
}

Point::Point(int x, int y, int r)
{
	cout << "인자있는 Point 생성자 호출" << endl;
}

Point::~Point()
{
	cout << "Point 소멸자 호출" << endl;
}
