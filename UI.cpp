#include<iostream>
#include<vector>
#include<string>

//#include"ui.h"

using namespace std;
class UI{
private:
	void Start();
	void Input_pw();
	void set_transaction();
	void Input_account_number();
	void ErrorMessage();
	void amount(int type);
protected:
	string Transaction_type[3];
public:
	void ErrorMessage(string);
	void ErrorMessage(int);
	void Display(int type){
		switch(type){
			case 0:
			return this->Start<int>();
			case 1:
			return this->Input_pw<int>();
			
			case 2:
			return this->set_transaction<int>();

			
			
		}
	}
};

class UI_ENG : public UI{
private:
	template<typename R>
	R Start(){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 WELCOME               "<<endl<<endl;
		cout<<"To start, Please insert your debit card"<<endl;
		cout<<"Card Number : ";
		R data;
		cin>>data;
		return data;
	};
	template<typename R>
	R Input_pw(){
		cout<<"Input Passwords : "<<endl;
		R data;
		cin>>data;
		return data;
	};
	template<typename R>
	R set_transaction(){
		cout<<"Select Transaction 1 : Deposit, 2 : Withdrawal, 3 : Transfer, 4 : Check Account,  or If you want cancel : 0"<<endl;
		R data;
		cin>>data;
		return data;
	};
	template<typename R>
	R Input_account_number(){
		cout<<"Input account number : "<<endl;
		R data;
		cin>>data;
		return data;
	}
	template<typename R>
	R amount(int type){
		cout<<"Input "<< Transaction_type[type] << " Amount : "<<endl;
		R data;
		cin>>data;
		return data;
	};
public:
	UI_ENG(){
		Transaction_type = ["Deposit", "Withdrawal", "Transfer"];
	}
	
};


int main(){
	UI_ENG a;
	int number = a.Display<int>(0);
	cout<<number<<endl;
}