#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class NameCard {
private:
	char* company;
	char* name;
	char* phone;
public:
	NameCard();
	void SetPerson(char* Name, char* Phone, char* Company);
	void ShowInfo();
};
NameCard::NameCard()
{
	company = NULL;
	name = NULL;
	phone = NULL;
}
void NameCard::SetPerson(char* Name, char* Phone, char* Company)
{
	name = Name;
	phone = Phone;
	company = Company;
}
void NameCard::ShowInfo() {
	cout << "회사명 : " << company << endl;
	cout << "성명 : " << name << endl;
	cout << "전화번호 : " << phone << endl;
};
int main() {
	NameCard person[3];
	char name[20];
	char phone[20];
	char company[20];
	char* strName;
	char* strPhone;
	char* strCompany;
	for (int i = 0; i < 3; i++) {
		cout << "회사명 : ";
		cin >> company;
		cout << "성명 : ";
		cin >> name;
		cout << "전화번호 : ";
		cin >> phone;
		strCompany = new char[strlen(company) + 1];
		strName = new char[strlen(name) + 1];
		strPhone = new char[strlen(phone) + 1];
		strcpy(strCompany, company);
		strcpy(strName, name);
		strcpy(strPhone, phone);
		person[i].SetPerson(strName, strPhone, strCompany);
	}
	for (int i = 0; i < 3; i++) {
		person[i].ShowInfo();
	}

}
