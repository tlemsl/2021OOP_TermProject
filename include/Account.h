#include<vector>
#include<map>
using namespace std;

class Account{
private:
	int Account_id;
	double Balance;
	string Name;
	map<pair<int, int>> Cards;
public:
	Account();
	Account(int id, stirng name, int balance);
	void Register_card(string, int);
	void Deposit(double data);
	bool Withdrawal(double data);
	bool check_card(int);
};