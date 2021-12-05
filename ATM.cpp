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
	bool Account_type1 = 1; // 1 : Primary 2 : Another
	bool Account_type2 = 1;
public:
	ATM(int, Bank*);
	ATM(int, double, Bank*, bool,  bool);
	void Set_admin(string, string);
	bool Admin_card_check(string);
	bool Admin_check(string, string);
	void Set_language();
	void Init_step();
	void Card_check_step();
	void Admin_mode(string);
	void Passwords_check_step(string)
	void Do_transaction();
	void Deposit(Account&);
	void Withdrawal(Account&);
	void Transfer(Account&);
	void Display_transaction_history();
	void run();
	void End_session();
}
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
void ATM::Set_admin(string cardnumber, string passwords){
	Admin_cards.insert(pair<string, string>(cardnumber, passwords));
	return;
}
bool Admin_card_check(string cardnumber){
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
void ATMCard_check_step(){
	while(1){
		string input;
		cin>>input;
		if(Linked_bank->Check_card(input)){
			Account_type1 = 1;
			return Passwords_check_step(input);
		}
		else if(Linked_bank->Check_card_linked_bank(input)){
			Account_type1 = 0;
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
		if(input == "0"){
			return End_session()
		}
		else if(Linked_bank->Check(cardnumber, passwords)){
			return Do_transaction(account);
		}
		else{
			Atm_ui.Error_message(1);
			continue;
		}
	}
	void End_session();
}
void Do_transaction(string cardnumber){
	Account target;
	if(Account_type1){
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
		return Transfer(target);
		default:
		return End_session();
	}
}
void Deposit(Account& account){
	double check, cash;
	Atm_ui.Display(3); // ;
	cin>>check;
	if(check == 0){
		return End_session();
	}
	Atm_ui.Display(4);
	cin>>cash;
	if(cash == 0){
		return End_session();
	}
	try{
		if(Account_type1){
			Link_bank->Deposit(account, check+cash);
			Session_log = format_strint()
			Print_log();
		}
		else{
			account.Deposit(account, check+cash - 500);
			Print_log();
		}
	}
	catch(int type){
		Atm_ui.Error_message(type)
		Deposit(account);
	}
}