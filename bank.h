/*
 * bank.h
 *
 *  Created on: 2014-3-2
 *      Author: Vergil
 */

#include "account.h"

const int MAX_NUM_ACCOUNTS = 30;


class Bank
{
  private:
    Account account[MAX_NUM_ACCOUNTS];
    int num_accounts;

  public:
    Bank();

    /* Accessor member functions */
    bool check_id(int account_id) const;
    void check_balance(int account_id) const;
    void check_all_balances() const;

    /* Mutator member functions */
    int create_account(const char* client_name);
    void deposit(float amount, int account_id);
    bool withdraw(float amount, int account_id);
};
