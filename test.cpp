#include<iostream>
#include<vector>
#include<map>
#include<memory>
using namespace std;
template<typename ... Args>
std::string format_string(const std::string& format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
	std::unique_ptr<char[]> buffer(new char[size]);
	snprintf(buffer.get(), size, format.c_str(), args ...);
	return std::string(buffer.get(), buffer.get() + size - 1);
}
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
class Bank{
private:
	string Bank_name;
	vector<Bank> Bank_list;
	vector<Account> Account_list;
public:
	Bank();
	Bank(string name);
	Bank(string name, vector<Bank>& list);
	string Get_Bank_name();

	void Add_account(Account&);
	Account& Search_Account(string);
	Account& Search_Account_linked_bank(string);
	bool Check_card(string);
	bool Check_card_linked_bank(string);
	bool Check_pw(string, string);
	void Deposit(Account&, double);
	void Withdrawal(Account&, double);
	friend void Link_bank(Bank&, Bank&);
	
};

int main(){
	Account account1(123, "Minjong", 100), account2(132, "Minjong", 1000);
	account1.Register_card("1111", "0514");
	account2.Register_card("2222", "0514");
	Bank Shinhan("Shinhan");
	Bank NongHyup("NongHyup");
	Bank Dummy("test");
	NongHyup.Add_account(account2);
	Shinhan.Add_account(account1);
	Link_bank(Shinhan, Dummy);
	Link_bank(Shinhan, NongHyup);

	try{
		
		cout<<Shinhan.Check_card("1111")<<endl;
		cout<<Shinhan.Check_card("2222")<<endl;
		cout<<Shinhan.Check_card_linked_bank("2222")<<endl;
		cout<<Shinhan.Check_pw("2222", "0514")<<endl;
		cout<<Shinhan.Check_pw("2222", "111")<<endl;
		cout<<Shinhan.Check_pw("1111", "0514")<<endl;
		}
	catch(string type){
		cout<<type<<endl;
	}
	catch(int type){
		cout<<type<<endl;
	}
}

Account::Account(){
	Account_id = 0;
	Balance = 0;
	Name = ""; 
}
Account::Account(int id, string name, double balance){
	Account_id = id;
	Name = name;
	Balance = balance;
	string log = "Account Owner : " + Name + format_string(", Account Number : %d",Account_id);
	Log.push_back(log);
}

void Account::Register_card(string cardnumber, string passwords){
	Cards.insert(pair<string, string>(cardnumber, passwords));
	return;
}
bool Account::Check_card(string cardnumber){

	auto item = Cards.find(cardnumber);
	return item != Cards.end();
}
bool Account::Check_pw(string cardnumber, string passwords){
	auto item = Cards.find(cardnumber);
	return passwords == item->second;
}

void Account::Logging(string data){
	Log.push_back(data);
}
vector<string>& Account::Get_log(){
	return this->Log;
}
string Account::Get_account_info(){
	return Log[0] + format_string(", Balance : %lf",this->Balance);
}
void Account::Deposit(double data){
	double temp = Balance + data;
	try{
		if(temp < 0){
			throw 2;
		}
		else{
			this->Balance = temp;
		}
	}
	catch(int type){
		throw;
	}
}
void Account::Withdrawal(double data){
	try{
		double temp = Balance - data;
		if(temp < 0){
			throw 2;
		}
		else{
			this->Balance = temp;
		}
	}
	catch(int type){
		throw;
	}
	
}
void Link_bank(Bank& b1, Bank& b2){
	b1.Bank_list.push_back(b2);
	b2.Bank_list.push_back(b1);
	return;
}
Bank::Bank(){
	Bank_name = "Shin han";
}
Bank::Bank(string name){
	Bank_name = name;
}
Bank::Bank(string name, vector<Bank>& list){
	Bank_name = name;
	Bank_list = list;
}
string Bank::Get_Bank_name(){return this->Bank_name;}
void Bank::Add_account(Account& account){Account_list.push_back(account);}

Account& Bank::Search_Account(string cardnumber){
	try{
		vector<Account>::iterator it = Account_list.begin();
		for(; it != Account_list.end(); ++it){
			if(it->Check_card(cardnumber)){return (*it);}
		}
		throw cardnumber;
	}
	catch(string cardnumber){
		throw;
	}
}
Account& Bank::Search_Account_linked_bank(string cardnumber){
	try{
		for(Bank& temp : Bank_list){
			try{
				return temp.Search_Account(cardnumber);
			}
			catch(string cardnumber){
				continue;
			}
		}
		throw cardnumber;
	}
	catch(string cardnumber){
		throw;
	}
}
void Bank::Deposit(Account& account, double amount){
	try{
		account.Deposit(amount);
	}
	catch(int type){
		throw;
	}
}
void Bank::Withdrawal(Account& account, double amount){
	try{
		account.Withdrawal(amount);
	}
	catch(int type){
		throw;
	}
}
bool Bank::Check_card(string cardnumber){
	try{
		auto temp = Search_Account(cardnumber);
		return true;
	}
	catch(string cardnumber){
		return false;
	}
}
bool Bank::Check_card_linked_bank(string cardnumber){
	try{
		auto temp = Search_Account_linked_bank(cardnumber);
		return true;
	}
	catch(string cardnumber){
		return false;
	}
}
bool Bank::Check_pw(string cardnumber, string passwords){
	try{
		auto temp = Search_Account(cardnumber);
		return temp.Check_pw(cardnumber, passwords);
	}
	catch(string){
		auto temp = Search_Account_linked_bank(cardnumber);
		return temp.Check_pw(cardnumber, passwords);
	}
}