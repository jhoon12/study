#pragma once
#include<iostream>
#include"account.h";
using namespace std;
class Account_handler_Class
{
private:
	account* accArr[100];
	int accNum = 0;
public:
	void ShowMenu()const;
	void MakeAccount();
	void DepositMoney();
	void ShowAllaccInfo();
	void with_draw_money();
	void EXIT()const;
	void make_nomal_account();
	void make_credit_account();

};

