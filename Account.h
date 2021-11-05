#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
private:
	double balance {0};
public:
	void set_balance(double bal);
	double get_balance();
	bool deposit(double amount);
	bool withdraw(double amount);
};

#endif