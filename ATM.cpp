#include<iostream>
#include<vector>
#include<Bank>
#include<map>
using namespace std;

class ATM{
private:
	int Serial_id = 0;
	bool Bank_type = false; // 0 : single bank, 1 : Multibank
	bool Language_type = false; // 0 : unilingual, 1 : bilingual
	map<int, int> admin_card;
	Bank bank;
public:
	ATM(int serial);
	ATM(int serial, bool bank_type, bool language_type);
	void set_admin(int, int);
	bool admin_check(int, int);
	void run();
}
ATM::ATM(int serial){
	Serial_id = serial;
}
ATM::ATM(int serial, bool bank_type, bool language_type){
	Serial_id = serial;
	Bank_type = bank_type;
	Language_type = language_type;
}
void ATM::set_admin(int cardnumber, int passwords){
	admin_card.insert(pair<int, int>(cardnumber, passwords));
	return;
}
void ATM::admin_check(int cardnumber, int passwords){
	auto item = admin_card.find(cardnumber);
	return item != admin_card.end();
}
void ATM::run(){
	UI atm_ui;
	if(language_type){
		cout<<"Select Language 1 : English, 2: Korean, 언어를 선택하세요 1 : 영어, 2 : 한국어";
		int type = 1;
		cin>>type;
		if(type == 1){
			atm_ui = UI_ENG();
		}
		else{
			atm_ui = UI_KOR();
		}
	}
	else{
		atm_ui = UI_ENG();
	}
	int input = atm_ui.Display(0);
	int cardnumber = input;
	input = atm_ui.Display(1);
	
}
