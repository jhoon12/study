#include<iostream>
#include"Point.h";
#include"Circle.h";
using namespace std;
int main() {
	Circle c1(3, 4, 5);
	c1.showCircle();
	c1.areaCircle();
	cout << endl << "���� �߽���, ������ ����" << endl;
	c1.setCircle(4, 5, 6);
	c1.showCircle();
	c1.areaCircle();
	return 0;
}