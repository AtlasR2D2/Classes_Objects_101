#include "Account_v2.h"
#include <iostream>
//#include <string>

using namespace std;

void Account_v2::set_balance(double bal){
	balance = bal;
};

double Account_v2::get_balance(){
	return balance;
};

bool Account_v2::deposit(double amount){
	if (amount > 0) {
		balance += amount;
		return true;
	}
	else
		return false;
};

bool Account_v2::withdraw(double amount){
	if (amount <= balance) {
		balance -= amount;
		cout << "Withdrawal successful. Revised Account Balance: " << balance << endl;
		return true;
	}
	else
		cout << "You have insufficient funds. Account Balance: " << balance << endl;
		return false;
};


