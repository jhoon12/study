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
	cout << "��������" << endl;
	cout << "����ID: " << accID << endl;
	cout << "�̸�: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
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
