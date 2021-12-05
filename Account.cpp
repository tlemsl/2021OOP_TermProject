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

void Account::Register_card(int cardnumber, int passwords){
	Cards.insert(pair<int, int>(cardnumber, passwords));
	return;
}
bool Account::Check_card(int cardnumber){

	auto item = Cards.find(cardnumber);
	return item != Cards.end();
}
bool Account::Check_pw(int cardnumber, int passwords){
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
	return Log[0] + format_string(", Balance : %lf",Balance);
}
void Account::Deposit(double data){

	this->Balance += data;
	return;
}
void Account::Withdrawal(double data){
	try{
		double temp = Balance - data;
		if(temp < 0){
			throw 0;
		}
		else{
			Balance = temp;
		}
	}
	catch(int type){
		throw;
	}
	
}