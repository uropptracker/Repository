#include <iostream>
#include "account.h"

using namespace std;

Account::Account()
{
	id = -1;
	balance = 0;
}

int Account::get_id() const
{
	return id;
}

const char* Account::get_name() const
{
	return name;
}

float Account::check_balance() const
{
	return balance;
}

void Account::set_id(int new_id)
{
	id = new_id;
}

void Account::set_name(const char* new_name)
{
	strcpy(name, new_name);
}

void Account::deposit(float amount)
{
	balance = balance+amount;
}

bool Account::withdraw(float amount)
{
	if (balance >= amount)
	{
		balance = balance-amount;
		return true;
	}
	else
	{
		cout << "Error: You don't have enough money!" << endl;
		return false;
	}
}
