Account::Account(){
	Account_id = 0;
	Balance = 0;
	Name = ""; 
}
Account::Account(int id, string name, int balance){
	Account_id = id;
	Name = name;
	Balance = balance;
}

void Account::Register_card(int cardnumber, int passwords){
	Cards.insert(pair<int, int>(cardnumber, passwords));
	return;
}
void Account::Deposit(double data){
	Balance += data;
}
bool Account::Withdrawal(double data){
	double temp = Balance - data;
	if(temp < 0){
		return false;
	}
	else{
		Balance = temp;
		return true;
	}
}
bool check_card(int cardnumber){
	auto item = Cards.find(cardnumber);
	return item != Cards.end();
}