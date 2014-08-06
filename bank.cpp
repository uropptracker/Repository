#include <iostream>
#include "bank.h"

using namespace std;

Bank::Bank()
{
	num_accounts = 0;
}

int Bank::create_account(const char* client_name)
{
	account[num_accounts].set_id(num_accounts);
	account[num_accounts].set_name(client_name);
	num_accounts++;
	return num_accounts-1;
}

void Bank::deposit(float amount, int account_id)
{
	account[account_id].deposit(amount);
}

bool Bank::withdraw(float amount, int account_id)
{
	return account[account_id].withdraw(amount);
}

bool Bank::check_id(int account_id) const
{
	if (account_id < num_accounts)
		return true;

	cout << "Error: Invalid account ID!" << endl;
	return false;
}

void Bank::check_balance(int account_id) const
{
	cout << "The balance in your account now is: "
			<< account[account_id].check_balance() << endl;
}

void Bank::check_all_balances() const
{
	for (int account_id = 0; account_id < num_accounts; account_id++)
	{
		cout << "Account " << account_id << ": " << account[account_id].get_name()
				<< ", " << account[account_id].check_balance() << endl;
	}
}
