#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<Account.h>
using namespace std;

class Bank{
private:
	string bank_name;
	map<pair<string, Bank>> bank_list;
	vector<Account> account_list;
public:
	Bank();
	Bank(sting name);
	Bank(sting name, &vector<bank> list);
	bool Deposit(int cardnumber, double amount);
	bool Withdrawal(int cardnumber, double amount);
	bool Transfer(int cardnumber, Account)
	vector<Account>::iterator Search_Account(int);
};

Bank::Bank(){
	bank_name = "Shin han";
}
Bank::Bank(string name){
	bank_name = name;
}
Bank::Bank(int name, &vector<bank> list){
	bank_name = name;
	bank_list = list;
}
vector<Account>::iterator Bank::Search_Account(int cardnumber){
	vector<Account>::iterator it = account_list.begin();
	for(; it != account_list.end(); ++it){
		if(it->check_card(cardnumber)){return it;}
	}
	return it;
}
bool Deposit(int cardnumber, double amount){
	try
}