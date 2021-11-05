#ifndef _ACCOUNT_v2_H_
#define _ACCOUNT_v2_H_


class Account_v2 {
private:
	double balance {0};
public:
	void set_balance(double bal);
	double get_balance();
	bool deposit(double amount);
	bool withdraw(double amount);
	
	
};

#endif // _ACCOUNT_v2_H_
