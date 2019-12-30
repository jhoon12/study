#include<iostream>
#include"Account_handler_Class.h"//account를 다루기 위한 함수의 class
using namespace std;


int main() {
	int choice;
	Account_handler_Class handler;
	while (1) {
		handler.ShowMenu();
		cout << "선택 :"; cin >> choice;
		switch(choice)
		{
		case 1:
			handler.MakeAccount();
			break;
		case 2:
			handler.DepositMoney();
			break;
		case 3:
			handler.with_draw_money();
			break;
		case 4:
			handler.ShowAllaccInfo();
			break;
		case 5:
			handler.EXIT();
			return 0;
			break;
		default:
			break;

		}
	}
}
