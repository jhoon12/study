#include "Account_handler_Class.h"
#include"nomal_account.h"

void Account_handler_Class::ShowMenu()const
{
	cout << "------menu-------" << endl;
	cout << "1. ���°��� " << endl;
	cout << "2 . �Ա� " << endl;
	cout << "3 . ��� " << endl;
	cout << "4. �������� ��ü ��� " << endl;
	cout << "5. ���α׷� ���� " << endl;
}

void Account_handler_Class::MakeAccount()
{
	int sel;
	cout << "[������������]" << endl;
	cout << " 1. ���뿹�ݰ��� ";
	cout << " 2 . �ſ뿹�ݰ���" << endl;
	cout << "���� : "; cin >> sel;
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : ", cin >> balance;
	cout << " ������ ", cin >> inter_rate;
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : ", cin >> balance;
	cout << " ������ ", cin >> inter_rate;
	cout << " �ſ���(1toA, 2toB, 3toC): "; cin >> credit_level;
	cout << endl;

	switch (credit_level) {
	case 1:
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);//enum ���
		break;
	case 2:
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);
		break;
	case 3:	
		accArr[accNum++] = new high_credit_account(id, balance, name, inter_rate, credit_level);
		break;
	}
}

