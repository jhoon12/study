#include "Account_handler_Class.h"
#include"nomal_account.h"

void Account_handler_Class::ShowMenu()const
{
	cout << "------menu-------" << endl;
	cout << "1. 계좌개설 " << endl;
	cout << "2 . 입금 " << endl;
	cout << "3 . 출금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl;
}

void Account_handler_Class::MakeAccount()
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << " 1. 보통예금계좌 ";
	cout << " 2 . 신용예금계좌" << endl;
	cout << "선택 : "; cin >> sel;
	if (sel == 1) {
		make_nomal_account();
	}
	else
		make_credit_account();
}

void Account_handler_Class::DepositMoney()
{
	int money;
	int id;
	cout << "[입 금] " << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "임금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다. " << endl << endl;
}

void Account_handler_Class::ShowAllaccInfo()
{
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}

void Account_handler_Class::with_draw_money()
{
	int money;
	int id;
	cout << "ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i]->GetAccID()) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다. " << endl;
}

void Account_handler_Class::EXIT()const
{
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}

void Account_handler_Class::make_nomal_account()
{
	int id;
	char name[100];
	int balance;
	int inter_rate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : ", cin >> balance;
	cout << " 이자율 ", cin >> inter_rate;
	cout << endl;

	accArr[accNum++] = new nomal_account(id, balance, name, inter_rate);
}

void Account_handler_Class::make_credit_account()
{

	int id;
	char name[100];
	int balance;
	int inter_rate;
	int credit_level;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : ", cin >> balance;
	cout << " 이자율 ", cin >> inter_rate;
	cout << " 신용등금(1toA, 2toB, 3toC): "; cin >> credit_level;
	cout << endl;

	switch (credit_level) {
	case 1:
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);//enum 사요
		break;
	case 2:
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);
		break;
	case 3:	
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);
		break;
	}
}

