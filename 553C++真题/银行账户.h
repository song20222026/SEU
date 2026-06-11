#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
class Account {
private:
	char accNumber[20];//账号
	double balance;//余额
public:
	Account(const char* num):balance(0) {
		strcpy(accNumber, num);
	}
	~Account(){ }

	double getBalance() {
		return balance;
	}
	char* getNum() { return accNumber; }
	double addBalance(double x) { balance += x; }
	double subBalance(double x) { balance -= x; }
	virtual void deposit(double money) = 0;	//存款
	virtual void withdraw(double money) = 0;//取款
	virtual void showInfo() {
		cout << accNumber << ":" << balance << endl;
	}

};

//储蓄账户
class SavingAccount : public Account{
public:
	SavingAccount(const char* p):Account(p){ }
	~SavingAccount(){ }
	virtual void deposit(double money) { 
		addBalance(money);
		cout << "储蓄账户" << getNum() << "：存款" << money << "元，余额" << getBalance() << "元" << endl;
	}
	virtual void withdraw(double money) {
		if (getBalance() < money)cerr << "余额不足" << endl;
		else subBalance(money);
	}

};

//活期账户
class CurrentAccount :public Account {
	CurrentAccount(const char* p) :Account(p) { }
	~CurrentAccount() { }
	virtual void deposit(double money) {
		addBalance(money);
		cout << "活期账户" << getNum() << "：存款" << money << "元，余额" << getBalance() << "元" << endl;
	}
	virtual void withdraw(double money) {
		if (getBalance() + 1000 < money)cerr << "余额不足" << endl;
		else if (getBalance() < money) {
			subBalance(money);
			cout << "活期账户" << getNum << "已透支" << money - getBalance() << "元" << endl;
		}
		else subBalance(money);
	}
};