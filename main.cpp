#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

#include "Account_v2.h"

using namespace std; // Bad practice

class Player {
// Access Modifier Public
public: // Accessible everywhere
	// attributes
	string name={"Player"};
	
	// methods
	void talk(string speech){
		cout << name << ": " << speech << endl;
	};
	bool is_dead() {
		return health == 0;		
	};
	void show_xp(){
		cout << name << " (xp): " << xp << endl;
	};
	void play_game(int level);
private: // Accesible only by members or friends of the class
	// attributes
	int health=100;
	int xp=0;
	// methods

protected: // used with inheritance, similar to private
	// attributes
	
	// methods
	
	
};

void Player::play_game(int level) {
	xp += level * 10;
};

void Account::set_balance(double bal){
	balance = bal;
};

double Account::get_balance(){
	return balance;
};

bool Account::deposit(double amount){
	if (amount > 0) {
		balance += amount;
		return true;
	}
	else
		return false;
};

bool Account::withdraw(double amount){
	if (amount <= balance) {
		balance -= amount;
		cout << "Withdrawal successful. Revised Account Balance: " << balance << endl;
		return true;
	}
	else
		cout << "You have insufficient funds. Account Balance: " << balance << endl;
		return false;
};

class Furniture {
private:
	string type {};
	double weight {};
	
public:
	// Constructors
	//Delegated Constructor
	Furniture() 
		: Furniture {"", 0}{
	};
	// Assignment not initialization
	Furniture(string type_x){
		type=type_x;
	};
	// Using Constructor Initialization Lists (Better Practice)
	Furniture(string type_x, double weight_x)
		:type{type_x},weight{weight_x}
	{
		
	};
	// Copy Constructor
	Furniture(const Furniture &source);
	// Destructors
	~Furniture() {
		cout << "Furniture destroyed." << endl;
		cout << "What have you done?!..." << endl;
	}
	// Methods
	void show_stats(){
		cout << "Furniture Stats" << endl;
		cout << "Type: " << type << endl;
		cout << "Weight: " << weight << endl;
	};
	string get_type(){
		return type;
	};
		
};

// Copy Constructor
Furniture::Furniture(const Furniture &source)
	: type{source.type},weight{source.weight}{
		cout << "Copy Constructor used..." << endl;
	};
	
void display_furniture_type(Furniture f) {
	cout << "Furniture Type: " << f.get_type() << endl;
};

class Teddy {
private:	
	// Attributes
	string name {};
public:
	// Constructor with default argument value
	Teddy(string name_x="Say my name say my name")
	: name{name_x}{};
	// Methods
	void output_name(){
		cout << "Teddy name: " << name << endl;
	};
	
};

int main(){
	
	Player michael;
	Player hero;
	
	Player players[] {michael,hero};
	
	vector<Player> player_vec {michael};
	player_vec.push_back(hero);
	
	Player *enemy {nullptr};
	enemy = new Player;

	enemy->name="enemy";
	
	cout << michael.is_dead() << endl;
	
	hero.name = "hero";
	
	hero.talk("I am hero");
	
	// Dereference first then access attribute/member
	if (!(*enemy).is_dead())
		// Arrow operator
		enemy->talk("I am still here...");
	else
		enemy->talk("I am no longer here...");
		
	michael.play_game(1);
	
	michael.show_xp();
	
	delete enemy;
	
	Account my_account;
	
	my_account.set_balance(100);
	
	cout << "My Account Balance: " << my_account.get_balance() << endl;
	
	bool exit_bank {false};
	int bank_option {0};
	double amount_x {0};
	
	while (!exit_bank) {
		cout << "Select Option" << endl << "1 - Deposit; 2 - Withdraw; 3 - Exit Bank" << endl;
		cin >> bank_option;
		switch (bank_option) {
		case 1:
			cout << "How much do you want to deposit: ";
			cin >> amount_x;
			my_account.deposit(amount_x);
			break;
		case 2:
		cout << "How much do you want to withdraw: ";
			cin >> amount_x;
			my_account.withdraw(amount_x);
			break;
		case 3:
			exit_bank = true;
			break;
		default:
			cout << "Invalid option. Try again." << endl;
		
		}
	}

	exit_bank = false;
	Account_v2 my_account_v2;
	
	
	while (!exit_bank) {
		cout << "Select Option" << endl << "1 - Deposit; 2 - Withdraw; 3 - Exit Bank" << endl;
		cin >> bank_option;
		switch (bank_option) {
		case 1:
			cout << "How much do you want to deposit: ";
			cin >> amount_x;
			my_account_v2.deposit(amount_x);
			break;
		case 2:
		cout << "How much do you want to withdraw: ";
			cin >> amount_x;
			my_account_v2.withdraw(amount_x);
			break;
		case 3:
			exit_bank = true;
			break;
		default:
			cout << "Invalid option. Try again." << endl;
		
		}
	}	
	
	{
		Furniture f1 {"Couch"};
		f1.show_stats();
		Furniture f2 {"Sofa",100};
		f2.show_stats();
		display_furniture_type(f2);
	}
	Teddy t1;
	Teddy t2 {"Doodoo"};
	t1.output_name();
	t2.output_name();
	
	
	return 0;
}