#pragma once
#include"account.h"
#include<iostream>
using namespace std;
class nomal_account :public account
{
private:
	int inter_rate;
public:
	nomal_account(int id, int money, char* name, int rate)
		: account(id, money, name), inter_rate(rate) {

	};

	virtual void Deposit(int money) {
		account::Deposit(money);
		account::Deposit(money * (inter_rate / 100.0));
	}

};

