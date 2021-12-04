#include<iostream>
#include<string>

//#include"ui.h"

using namespace std;
class UI{
private:
	virtual string Transaction_type;
	virtual int Start();
	virtual int Input_pw();
	virtual int set_transaction();
	virtual int Input_account_number();
	virtual void ErrorMessage();
	virtual double amount(int type);
public:
	virtual UI();
	void Display(int type);
};

class UI_ENG() : public UI{
private:
	int Start(){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 WELCOME               "<<endl<<endl;
		cout<<"To start, Please insert your debit card"<<endl;
		cout<<"Card Number : ";
		int data;
		cin>>data;
		return data;
	};
	int Input_pw(){
		cout<<"Input Passwords : "<<endl;
		int data;
		cin>>data;
		return data;
	};
	int set_transaction(){
		cout<<"Select Transaction 1 : Deposit, 2 : Withdrawal, 3 : Transfer, 4 : Check Account,  or If you want cancel : 0"<<endl;
		int data;
		cin>>data;
		return data;
	};
	int Input_account_number(){
		cout<<"Input account number : "<<endl;
		int data;
		cin>>data;
		return data;
	}
	double amount(int type){
		cout<<"Input "<< Transaction_type[type] << " Amount : "<<endl;
		double data;
		cin>>data;
		return data;
	};
public:
	UI{
		Transaction_type = = ["Deposit", "Withdrawal", "Transfer"];
	}
	void Display(int type){
		switch(type){
			case 0:
			this->Start();
			break;
			case 1:
			this->Input_pw();
			break;
			case 2:
			this->set_transaction();
			break;
			
		}
	}
}

class UI_KOR() : public UI{
private:
	int Start();
	int Input_pw();
	int set_transaction();
	int Input_account_number();
	double amount();
public:
	void Display(int type);
}


int main(){
	UI a(0);
	a.Default();
	a.Print_messge("안녕하세요");
}