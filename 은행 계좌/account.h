#pragma once
class account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	int GetAccID();
	account(int ID, int money, char* name);
	void showAccInfo();
	void Deposit(int money);
	int Withdraw(int money);
	~account();
};


