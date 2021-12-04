#include<iostream>
#include<string>
#include<vector>
#include<Account.h>
using namespace std;

class Bank{
private:
	string bank_name;
	vector<Bank> bank_list;
	vector<Account> account_list;
public:
	Bank();
	Bank(sting name, &vector<bank> list);
	bool Deposit(int cardnumber, int amount);
	bool Withdrawal(int cardnumber, int amount);
	bool Transfer(int cardnumber, )
};