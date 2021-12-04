#include<vector>
#include<string>
using namespace std;

class Account{
private:
	int Account_id;
	double Balance;
	string Name;
	vector<int> CardNumbers;
public:
	Account();
	Account(int id, stirng name, int balance);
	Account(int id, string name, int balance, &vector<int> cardnumbers);
	void Deposit(double data);
	bool Withdrawal(double data);
	void AppendCard(int cardnumber);
}