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
Account::Account(int id, string name, int balance, &vector<int> cardnumbers){
	Account_id = id;
	Name = name;
	Balance = balance;
	CardNumbers = cardnumbers;
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
void Account::AppendCard(int cardnumber){
	CardNumbers.push_back(cardnumber);
}