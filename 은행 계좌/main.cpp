#include<iostream>
#include"account.h"
using namespace std;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void ShowAllaccInfo();
void with_draw_money();
void EXIT();

account* accArr[100];
int accNum = 0;

int main() {
	int choice;
	while (1) {
		ShowMenu();
		cout << "선택 :"; cin >> choice;
		switch(choice)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			DepositMoney();
			break;
		case 3:
			with_draw_money();
			break;
		case 4:
			ShowAllaccInfo();
			break;
		case 5:
			EXIT();
			return 0;
			break;
		default:
			break;

		}
	}
}
void ShowMenu() {
	cout << "------menu-------" << endl;
	cout << "1. 계좌개설 " << endl;
	cout << "2 . 입금 " << endl;
	cout << "3 . 출금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl;
}

void MakeAccount() {
	int id;
	char name[20];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new account(id, balance, name);
}

void DepositMoney() {
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

void ShowAllaccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}

void with_draw_money() {
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

void EXIT() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
	//return 0;
}