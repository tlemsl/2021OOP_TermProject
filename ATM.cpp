#include<iostream>
#include<vector>
#include<Bank>
#include<map>
using namespace std;

class ATM{
private:
	int Serial_id = 0;
	double Atm_cash_balance = 10000000; // 100만원
	double Atm_check_balance = 0;
	double Max_input_cash = 1000000; //100 만원
	double Max_input_check = 10,000,000; //1000만원

	bool Bank_type = false; // 0 : single bank, 1 : Multibank
	bool Language_type = false; // 0 : unilingual, 1 : bilingual

	map<int, int> Admin_cards;

	Bank* Linked_bank;
	UI Atm_ui;
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
	void Do_transaction();
	void Deposit(Account*);
	void Withdrawal(Account*);
	void Transfer();
	void Display_transaction_history();
	void End_session();
	void Print_log();
};
ATM::ATM(int serial, Bank* bank){
	Serial_id = serial;
	Link_bank = bank;
}
ATM::ATM(int serial, double balance, Bank* bank,bool bank_type, bool language_type){
	Serial_id = serial;
	Atm_cash_balance = balance;
	Link_bank = bank;
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
	return passwords = item->second;
}
void ATM::Set_language(){
	if(language_type){
		cout<<"Select Language 1 : English, 2: Korean, 언어를 선택하세요 1 : 영어, 2 : 한국어";
		int type = 1;
		cin>>type;
		if(type == 1){
			Atm_ui = UI_ENG();
		}
		else{
			Atm_ui = UI_KOR();
		}
	}
	else{
		Atm_ui = UI_ENG();
	}
	Init_step();
	return;
}
void ATM::Init_step(){
	Atm_ui.Display(0);
	Card_check_step();
	return;
}
void ATM::Card_check_step(){
	while(1){
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
			Atm_ui.Error_message(0);
		}
	}
}
void ATM::Passwords_check_step(string cardnumber){
	for(int i=0; i<3; i++){
		Atm_ui.Display(1);
		string passwords;
		cin>>passwords;
		if(Input_check(passwords)){return End_session();}
		if(Linked_bank->Check(cardnumber, passwords)){
			return Do_transaction(account);
		}
		else{
			Atm_ui.Error_message(1);
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
	Atm_ui.Display(2);
	int mode;
	cin>>mode;
	switch(mode){
		case "1":
		return Deposit(target);
		case "2":
		return Withdrawal(target);
		case "3":
		return Transfer();
		default:
		return End_session();
	}
}
void ATM::Deposit(Account* account){
	int sel;
	double check, cash;
	Atm_ui.Display(3); // Select Cash or Check;
	cin>>sel;
	Input_check(sel);
	else if(sel == 1){
		Atm_ui.Display(4);
		cin>>cash;
		Input_check(cash);
		if(cash>Max_input_cash){
			Atm_ui.Error_message(4);
			return Deposit(account);
		}
	}
	else if(sel == 2){
		Atm_ui.Display(5);
		cin>>check;
		Input_check(check);
		if(check>Max_input_check){
			Atm_ui.Error_message(4);
			return Deposit(account);
		}
	}
	else{return End_session();}
	try{
		double fee = Deposit_fee[Account_type1];
		Linked_bank->Deposit(account, cach + check - fee);
		Atm_cash_balance += cash;
		Atm_check_balance += check;
		return Print_log();
	}
	catch(int type){
		Atm_ui.Error_message(type);
		return this->Deposit(account);
	}
}
void ATM::Withdrawal(Account* account){
	double amount;
	Atm_ui.Display(4);
	cin>>amount;
	Input_check(amount);
	if(amount>Atm_cash_balance){
		Atm_ui.Error_message(2);
		return Withdrawal(account);
	}
	try{
		double fee = Withdrawal_fee[Account_type1];
		this->Linked_bank->Withdrawal(account, cach - fee);
		this->Atm_cash_balance-=cash;
		return Print_log();
	}
	catch(int type){
		Atm_ui.Error_message(type);
		return this->Withdrawal(account);
	}
}
void ATM::Transfer(){
	int type;
	Atm_ui.Display(6);
	cin>>type;
	try{
		Input_check(type);
		Account* account1, account2;
		if(type == 1){
			int account_number;
			Atm_ui.Display(7);
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
			Atm_ui.Display(8);
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
			Atm_ui.Display(9);
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
			Atm_ui.Display(8);
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
			Atm_ui.Display(9);
			Atm_ui.Display(4);
			double amount;
			cin>>amount;
			try{
				Linked_bank->Deposit(account2, amount - fee);
				cash+= amount;
				return Print_log();
			}
			catch(int type){
				throw;
			}

		}
		else{return End_session();}
	}
	catch(int type){
		Atm_ui.Error_message(type);
		return this->Transfer();
	}
} 
void End_session(){
	Atm_ui.Display(10);
	return;
}
void Print_log(){
	cout<<"test"<<endl;
}
void run(){
	Set_language();
	return;
}




int main(){
	cout<<"test"<<endl;
}






















