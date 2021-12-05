#include<iostream>
#include<vector>
#include<map>
#include<memory>
using namespace std;
class Account{
private:
	int Account_id;
	double Balance;
	string Name;
	map<string, string> Cards;
	vector<string> Log;
public:
	Account();
	Account(int id, string name, double balance);
	void Register_card(string, string);

	bool Check_card(string);
	bool Check_pw(string, string);
	void Logging(string);
	vector<string>& Get_log();
	string Get_account_info();
	void Deposit(double);
	void Withdrawal(double);
};