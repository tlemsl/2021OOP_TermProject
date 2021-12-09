#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
//#include"ui.h"

using namespace std;
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
	virtual void Session_display(vector<string>&) = 0;
	virtual void Session_history(vector<vector<string>>&) = 0;
	virtual void Account_history(vector<string>&, vector<vector<string>>&) = 0;
public:
	void Display(int type){
		(this->*Display_functions[type])();
	}
	void Error_message(int type){
		(this->*Error_functions[type])();
	}
	void Display_session(vector<string>& log){
		Session_display(log);
	}
	void Display_session_history(vector<vector<string>>& logs){
		Session_history(logs);
	}
	void Display_account(vector<string>& info, vector<vector<string>>& logs){
		Account_history(info, logs);
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
	void Session_display(vector<string>& log){
		cout<<setw(10)<<"User name"<<setw(17)<<"Transaction type"<<setw(15)<<"Amount"<<setw(17)<<"Source Account"<<setw(20)<<"Destinaion Account"<<setw(15)<<"fee"<<endl;
		cout<<setw(10)<<log[0]<<setw(17)<<log[1]<<setw(15)<<log[2]<<setw(17)<<log[3]<<setw(20)<<log[4]<<setw(15)<<log[5]<<endl;
	}
	void Session_history(vector<vector<string>>& logs){
		cout<<setw(3)<<"id"<<setw(10)<<"User name"<<setw(17)<<"Transaction type"<<setw(15)<<"Amount"<<setw(17)<<"Source Account"<<setw(20)<<"Destinaion Account"<<setw(15)<<"fee"<<endl;
		int id = 0
		for(vector<string>& log : logs){
			cout<<setw(3)<<id<<setw(10)<<log[0]<<setw(17)<<log[1]<<setw(15)<<log[2]<<setw(17)<<log[3]<<setw(20)<<log[4]<<setw(15)<<log[5]<<endl;
			id++;
		}
	}
	void Account_history(vector<string>& info, vector<vector<string>>& logs){
		cout<<setw(10)<<"Name"<<setw(15)<<"Account Number"<<setw(15)<<"Balance"<<endl;
		cout<<setw(10)<<info[0]<<setw(15)<<info[1]<<setw(15)<<info[2]<<endl;
		cout<<"Transaction History"<<endl;
		cout<<setw(3)<<"id"<<setw(15)<<"Deposit"<<setw(15)<<"Withdrawal"<<setw(15)<<"Balance"<<endl;
		int id = 0
		for(vector<string>& log : logs){
			cout<<setw(3)<<id<<setw(15)<<log[0]<<setw(15)<<log[1]<<setw(15)<<log[2]<<endl;
			id++;
		}
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
	void Session_display(vector<string>& log){

		cout<<setw(10)<<"User name"<<setw(17)<<"Transaction type"<<setw(10)<<"Amount"<<setw(17)<<"Source Account"<<setw(20)<<"Destinaion Account"<<setw(5)<<"fee"<<endl;
		cout<<setw(10)<<log[0]<<setw(17)<<log[1]<<setw(10)<<log[2]<<setw(17)<<log[3]<<setw(20)<<log[4]<<setw(5)<<log[5]<<endl;
	}
};

int main(){
	UI_ENG test;
	vector<string> log(6);
	log[0] = "me";
	log[1] = "0";
	log[2] = "1000";

	test.Display_session(log);
}