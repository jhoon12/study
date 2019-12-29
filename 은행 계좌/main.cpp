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
		cout << "���� :"; cin >> choice;
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
	cout << "1. ���°��� " << endl;
	cout << "2 . �Ա� " << endl;
	cout << "3 . ��� " << endl;
	cout << "4. �������� ��ü ��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void MakeAccount() {
	int id;
	char name[20];
	int balance;

	cout << "[���°���]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new account(id, balance, name);
}

void DepositMoney() {
	int money;
	int id;
	cout << "[�� ��] " << endl;
	cout << "����ID : "; cin >> id;
	cout << "�ӱݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
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
	cout << "��ݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i]->GetAccID()) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�. " << endl;

}

void EXIT() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
	//return 0;
}