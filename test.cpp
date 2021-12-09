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
class UI{
private:
	void (UI::*Display_functions[11])()={&UI::Input_card, &UI::Input_pw, &UI::Set_transaction, &UI::Sel_cash_check, &UI::Input_cash, &UI::Input_check, &UI::Sel_cash_check, &UI::Input_account_number_source,&UI::Input_account_number_dest, &UI::Input_transfer_amount, &UI::End_session};
	void (UI::*Error_functions[5])()={&UI::Wrong_cardnumber, &UI::Wrong_passwords, &UI::Lack_of_balance, &UI::Wrong_account_number, &UI::Over_max_atm_input};
protected:
	string Transaction_type[3];
	virtual void End_session() = 0;
	virtual void End_session_message() = 0;
	virtual void Input_card() = 0;
	virtual void Input_pw() = 0;
	virtual void Set_transaction() = 0;
	virtual void Sel_cash_check() = 0;
	virtual void Input_cash() = 0;
	virtual void Input_check() = 0;
	virtual void Sel_account_cash() = 0;
	virtual void Input_account_number_source() = 0;
	virtual void Input_account_number_dest() = 0;
	virtual void Input_transfer_amount() = 0;
	virtual void Wrong_cardnumber() = 0;
	virtual void Wrong_passwords() = 0;
	virtual void Lack_of_balance() = 0;
	virtual void Wrong_account_number() = 0;
	virtual void Over_max_atm_input() = 0;
public:
	void Display(int type){
		(this->*Display_functions[type])();
	}
	void Error_message(int type){
		(this->*Error_functions[type])();
	}
};
class UI_ENG : public UI{
protected:
	void End_session(){
		cout<<"Session is end Thank you"<<endl;
	}
	void End_session_message(){
		cout<<"If you want end this session press 0"<<endl;
	}
	void Input_card(){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 WELCOME               "<<endl<<endl;
		cout<<"To start, Please insert your debit card"<<endl;
		cout<<"Card Number : ";
	};
	void Input_pw(){
		End_session_message();
		cout<<"Input Passwords : "<<endl;
	};
	void Set_transaction(){
		End_session_message();
		cout<<"Select Transaction 1 : Deposit, 2 : Withdrawal, 3 : Transfer, 4 : Check Account "<<endl;
	};
	void Sel_cash_check(){
		End_session_message();
		cout<<"Select Deposit type, 1 : Cash, 2 : Check "<<endl;
	}
	void Input_cash(){
		End_session_message();
		cout<<"Input Cash : "<<endl;
	};
	void Input_check(){
		End_session_message();
		cout<<"Input Check : "<<endl;
	}
	void Sel_account_cash(){
		End_session_message();
		cout<<"Select Transfer Type, Account : 1, Cash : 2"<<endl;
	}
	void Input_account_number_source(){
		End_session_message();
		cout<<"Input Source Account Number : "<<endl;
	}
	void Input_account_number_dest(){
		End_session_message();
		cout<<"Input Destination Account Number : "<< endl;
	}
	void Input_transfer_amount(){
		End_session_message();
		cout<<"Input Transfer Amount : "<<endl;
	}
	void Wrong_cardnumber(){
		cout<<"Input Wrong cardnumber"<<endl;
	}
	void Wrong_passwords(){
		cout<<"Input Wrong passwords"<<endl;
	}
	void Lack_of_balance(){
		cout<<"Lack_of_balance error"<<endl;
	}
	void Wrong_account_number(){
		cout<<"Input Wrong Account number"<<endl;
	}
	void Over_max_atm_input(){
		cout<<"Over Max ATM input"<<endl;
	}
};
class UI_KOR : public UI{
protected:
	void End_session(){
		cout<<"현재 세션이 종료되었습니다. 감사합니다."<<endl;
	}
	void End_session_message(){
		cout<<"세션을 끝내고 싶으시면 0을 누르십시오"<<endl;
	}
	void Input_card(){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 반갑습니다              "<<endl<<endl;
		cout<<"시작하시려면 카드를 입력해 주세요"<<endl;
		cout<<"카드 번호 : ";
	};
	void Input_pw(){
		End_session_message();
		cout<<"비밀 번호 : "<<endl;
	};
	void Set_transaction(){
		End_session_message();
		cout<<"Select Transaction 1 : Deposit, 2 : Withdrawal, 3 : Transfer, 4 : Check Account "<<endl;
	};
	void Sel_cash_check(){
		End_session_message();
		cout<<"Select Deposit type, 1 : Cash, 2 : Check "<<endl;
	}
	void Input_cash(){
		End_session_message();
		cout<<"Input Cash : "<<endl;
	};
	void Input_check(){
		End_session_message();
		cout<<"Input Check : "<<endl;
	}
	void Sel_account_cash(){
		End_session_message();
		cout<<"Select Transfer Type, Account : 1, Cash : 2"<<endl;
	}
	void Input_account_number_source(){
		End_session_message();
		cout<<"Input Source Account Number : "<<endl;
	}
	void Input_account_number_dest(){
		End_session_message();
		cout<<"Input Destination Account Number : "<< endl;
	}
	void Input_transfer_amount(){
		End_session_message();
		cout<<"Input Transfer Amount : "<<endl;
	}
	void Wrong_cardnumber(){
		cout<<"Input Wrong cardnumber"<<endl;
	}
	void Wrong_passwords(){
		cout<<"Input Wrong passwords"<<endl;
	}
	void Lack_of_balance(){
		cout<<"Lack_of_balance error"<<endl;
	}
	void Wrong_account_number(){
		cout<<"Input Wrong Account number"<<endl;
	}
	void Over_max_atm_input(){
		cout<<"Over Max ATM input"<<endl;
	}
};
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
	int Get_account_number();
	string Get_account_info();
	void Register_card(string, string);

	bool Check_card(string);
	bool Check_pw(string, string);
	void Logging(string);
	vector<string>& Get_log();
	
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
	Account* Search_Account(string);
	Account* Search_Account(int);
	Account* Search_Account_linked_bank(string);
	Account* Search_Account_linked_bank(int);
	bool Check_card(string);
	bool Check_card_linked_bank(string);
	bool Check_pw(string, string);
	void Deposit(Account*, double);
	void Withdrawal(Account*, double);
	friend void Link_bank(Bank&, Bank&);
	
};
class ATM{
private:
	int Serial_id = 0;
	double Atm_cash_balance = 10000000; // 100만원
	double Atm_check_balance = 0;
	double Max_input_cash = 1000000; //100 만원
	double Max_input_check = 10000000; //1000만원

	bool Bank_type = false; // 0 : single bank, 1 : Multibank
	bool Language_type = false; // 0 : unilingual, 1 : bilingual

	map<string, string> Admin_cards;

	Bank* Linked_bank;
	UI* Atm_ui;
	vector<string> Atm_log;
	string Session_log;
	int Session_count = 0;
	bool Account_type1 = 0; // 0 : Primary 1 : Another
	bool Account_type2 = 0;
	double Deposit_fee[2] = {0.0, 500.0};
	double Withdrawal_fee[2] = {500.0, 1000.0};
	double Transfer_fee[3] = {1500, 2000, 2500};
public:
	ATM(int, Bank*);
	ATM(int, double, Bank*, bool,  bool);
	bool Input_check(int);
	bool Input_check(string);
	bool Input_check(double);
	void Set_admin(string, string);
	bool Admin_card_check(string);
	bool Admin_check(string, string);
	void Set_language();
	void Init_step();
	void Card_check_step();
	void Admin_mode(string);
	void Passwords_check_step(string);
	void Do_transaction(string);
	void Deposit(Account*);
	void Withdrawal(Account*);
	void Transfer();
	void Display_transaction_history();
	void End_session();
	void Print_log();
	void Run();
};

ATM::ATM(int serial, Bank* bank){
	Serial_id = serial;
	Linked_bank = bank;
}
ATM::ATM(int serial, double balance, Bank* bank,bool bank_type, bool language_type){
	Serial_id = serial;
	Atm_cash_balance = balance;
	Linked_bank = bank;
	Bank_type = bank_type;
	Language_type = language_type;
}
bool ATM::Input_check(int input){
	return input == 0;
}
bool ATM::Input_check(string input){
	return input == "0";
}
bool ATM::Input_check(double input){
	return input == 0.0;
}
void ATM::Set_admin(string cardnumber, string passwords){
	Admin_cards.insert(pair<string, string>(cardnumber, passwords));
	return;
}
bool ATM::Admin_card_check(string cardnumber){
	auto item = Admin_cards.find(cardnumber);
	return item != Admin_cards.end();
}
bool ATM::Admin_check(string cardnumber, string passwords){
	auto item = Admin_cards.find(cardnumber);
	return passwords == item->second;
}
void ATM::Set_language(){
	if(Language_type){
		cout<<"Select Language 1 : English, 2: Korean, 언어를 선택하세요 1 : 영어, 2 : 한국어"<<endl;;
		int type = 1;
		cin>>type;
		if(type == 1){
			Atm_ui = new UI_ENG;
		}
		else{
			Atm_ui = new UI_ENG;
		}
	}
	else{
		Atm_ui = new UI_ENG;
	}
	Init_step();
	return;
}
void ATM::Init_step(){
	Atm_ui->Display(0);
	Card_check_step();
	return;
}
void ATM::Card_check_step(){
	string input;
	cin>>input;
	if(Input_check(input)){return End_session();}
	if(Linked_bank->Check_card(input)){
		Account_type1 = 0;
		return Passwords_check_step(input);
	}
	else if(Linked_bank->Check_card_linked_bank(input)){
		Account_type1 = 1;
		return Passwords_check_step(input);
	}
	else{
		Atm_ui->Error_message(0);
		return Init_step();
	}
}

void ATM::Passwords_check_step(string cardnumber){
	for(int i=0; i<3; i++){
		Atm_ui->Display(1);
		string passwords;
		cin>>passwords;
		if(Input_check(passwords)){return End_session();}
		if(Linked_bank->Check_pw(cardnumber, passwords)){
			return Do_transaction(cardnumber);
		}
		else{
			Atm_ui->Error_message(1);
			continue;
		}
	}
	void End_session();
}
void ATM::Do_transaction(string cardnumber){
	Account* target;
	if(!Account_type1){
		target = Linked_bank->Search_Account(cardnumber);
	}
	else{
		target = Linked_bank->Search_Account_linked_bank(cardnumber);
	}
	Atm_ui->Display(2);
	int mode;
	cin>>mode;
	switch(mode){
		case 1:
		return Deposit(target);
		case 2:
		return Withdrawal(target);
		case 3:
		return Transfer();
		default:
		return End_session();
	}
}
void ATM::Deposit(Account* account){
	int sel;
	double check = 0, cash = 0;
	Atm_ui->Display(3); // Select Cash or Check;
	cin>>sel;
	if(sel == 1){
		Atm_ui->Display(4);
		cin>>cash;
		Input_check(cash);
		if(cash>Max_input_cash){
			Atm_ui->Error_message(4);
			return Deposit(account);
		}
	}
	else if(sel == 2){
		Atm_ui->Display(5);
		cin>>check;
		Input_check(check);
		if(check>Max_input_check){
			Atm_ui->Error_message(4);
			return Deposit(account);
		}
	}
	else{return End_session();}
	try{
		double fee = Deposit_fee[Account_type1];
		Linked_bank->Deposit(account, cash + check - fee);
		Atm_cash_balance += cash;
		Atm_check_balance += check;
		return Print_log();
	}
	catch(int type){
		Atm_ui->Error_message(type);
		return this->Deposit(account);
	}
}
void ATM::Withdrawal(Account* account){
	double cash;
	Atm_ui->Display(4);
	cin>>cash;
	if(Input_check(cash)){return End_session();}
	if(cash>Atm_cash_balance){
		Atm_ui->Error_message(2);
		return Withdrawal(account);
	}
	try{
		double fee = Withdrawal_fee[Account_type1];
		this->Linked_bank->Withdrawal(account, cash - fee);
		this->Atm_cash_balance-=cash;
		return Print_log();
	}
	catch(int type){
		Atm_ui->Error_message(type);
		return this->Withdrawal(account);
	}
}
void ATM::Transfer(){
	int type;
	Atm_ui->Display(6);
	cin>>type;
	try{
		Input_check(type);
		Account* account1;
		Account* account2;
		if(type == 1){
			int account_number;
			Atm_ui->Display(7);
			cin>>account_number;
			Input_check(account_number);
			try{
				account1 = Linked_bank->Search_Account(account_number);
				Account_type1 = 0;
			}
			catch(int type){
				try{
					account1 = Linked_bank->Search_Account_linked_bank(account_number);
					Account_type1 = 1;
				}
				catch(int typee){
					throw;
				}
			}
			Atm_ui->Display(8);
			cin>>account_number;
			Input_check(account_number);
			try{
				account2 = Linked_bank->Search_Account(account_number);
				Account_type2 = 0;
			}
			catch(int type){
				try{
					account2 = Linked_bank->Search_Account_linked_bank(account_number);
					Account_type2 = 1;
				}
				catch(int typee){
					throw;
				}
			}
			double fee = Transfer_fee[Account_type1+Account_type2];
			Atm_ui->Display(9);
			double amount;
			cin>>amount;
			try{
				Linked_bank->Withdrawal(account1, amount - fee);
				Linked_bank->Deposit(account2, amount - fee);
				return Print_log();
			}
			catch(int type){
				throw;
			}
		}
		else if(type == 2){
			int account_number;
			Atm_ui->Display(8);
			cin>>account_number;
			Input_check(account_number);
			try{
				account2 = Linked_bank->Search_Account(account_number);
				Account_type2 = 0;
			}
			catch(int type){
				try{
					account2 = Linked_bank->Search_Account_linked_bank(account_number);
					Account_type2 = 1;
				}
				catch(int typee){
					throw;
				}
			}
			double fee = Transfer_fee[Account_type1+Account_type2];
			Atm_ui->Display(9);
			Atm_ui->Display(4);
			double amount;
			cin>>amount;
			try{
				Linked_bank->Deposit(account2, amount - fee);
				Atm_cash_balance += amount;
				return Print_log();
			}
			catch(int type){
				throw;
			}

		}
		else{return End_session();}
	}
	catch(int type){
		Atm_ui->Error_message(type);
		return this->Transfer();
	}
} 
void ATM::End_session(){
	Atm_ui->Display(10);
	return;
}
void ATM::Print_log(){
	cout<<"test"<<endl;
	End_session();
}
void ATM::Run(){
	Set_language();
	return;
}



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
	ATM test_atm(123, 500000, &Shinhan, 1,1);
	try{
		/*
		cout<<Shinhan.Search_Account_linked_bank("2222")->Get_account_info()<<endl;
		cout<<Shinhan.Check_card("1111")<<endl;
		cout<<Shinhan.Check_card("2222")<<endl;
		cout<<Shinhan.Check_card_linked_bank("2222")<<endl;
		cout<<Shinhan.Check_pw("2222", "0514")<<endl;
		cout<<Shinhan.Check_pw("2222", "111")<<endl;
		cout<<Shinhan.Check_pw("1111", "0514")<<endl;
		*/
		test_atm.Run();
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
int Account::Get_account_number(){return this->Account_id;}
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

Account* Bank::Search_Account(string cardnumber){
	try{
		vector<Account>::iterator it = Account_list.begin();
		for(; it != Account_list.end(); ++it){
			if(it->Check_card(cardnumber)){return &(*it);}
		}
		throw cardnumber;
	}
	catch(string cardnumber){
		throw;
	}
}
Account* Bank::Search_Account(int account_number){
	try{
		vector<Account>::iterator it = Account_list.begin();
		for(; it != Account_list.end(); ++it){
			if(it->Get_account_number() == account_number){return &(*it);}
		}
		throw 3;
	}
	catch(int type){
		throw;
	}
}
Account* Bank::Search_Account_linked_bank(string cardnumber){
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
Account* Bank::Search_Account_linked_bank(int account_number){
	try{
		for(Bank& temp : Bank_list){
			try{
				return temp.Search_Account(account_number);
			}
			catch(int type){
				continue;
			}
		}
		throw 3;
	}
	catch(int type){
		throw;
	}

}
void Bank::Deposit(Account* account, double amount){
	try{
		account->Deposit(amount);
	}
	catch(int type){
		throw;
	}
}
void Bank::Withdrawal(Account* account, double amount){
	try{
		account->Withdrawal(amount);
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
		return temp->Check_pw(cardnumber, passwords);
	}
	catch(string){
		auto temp = Search_Account_linked_bank(cardnumber);
		return temp->Check_pw(cardnumber, passwords);
	}
}
