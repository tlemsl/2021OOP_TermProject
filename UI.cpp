#include<iostream>
#include<string>

//#include"ui.h"

using namespace std;
class UI{
private:
	bool Type = 1; // 0 : Korean,  1 : English
public:
	UI(bool type);
	void Default();
	void Print_messge(string msg);
};



UI::IO(bool type){ Type = type;}

void UI::Default(){
	if(Type){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 WELCOME               "<<endl<<endl;
		cout<<"To start, Please insert your debit card"<<endl;
		cout<<"Card Number : ";
	}
	else{
		cout<<"-------------------------------------------"<<endl;
		cout<<"                 안녕하세요               "<<endl<<endl;
		cout<<"     시작하시려면 카드를 입력해주세요!     "<<endl;
		cout<<"카드번호 : ";		
	}

}
void UI::Print_messge(string msg){
	cout<<msg<<endl;
}

int main(){
	UI a(0);
	a.Default();
	a.Print_messge("안녕하세요");
}