#include "account.h"
#include<iostream>
using namespace std;
#include <string.h>

int account::GetAccID()
{
	return accID;
}

account::account(int ID, int money,char* name)
{
	accID = ID;
	balance = money;
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
	//cusName = name;
}

void account::showAccInfo()
{
	cout << "°èÁÂÁ¤º¸" << endl;
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ¸§: " << cusName << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
}

void account::Deposit(int money)
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
