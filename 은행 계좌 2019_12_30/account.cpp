#include "account.h"
#include<iostream>
using namespace std;
#include <string.h>

int account::GetAccID() const
{
	return accID;
}

account::account(int ID, int money,char* name)
{
	accID = ID;
	balance = money;
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

void account::showAccInfo() const
{
	cout << "계좌정보" << endl;
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}

void account::Deposit(int money)//왜 여기에 virtual안되나요?
{
	balance += money;
}

int account::Withdraw(int money){

	if(balance < money)
	return 0;
	else {
		balance -= money;
		return money;
	}
}

account::~account()
{
	delete[]cusName;
}
