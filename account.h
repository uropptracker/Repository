/*
 * account.h
 *
 *  Created on: 2014-3-2
 *      Author: Vergil
 */


class Account
{
  private:
    int id;
    char name[50];
    float balance;

  public:
    Account();

    /* Accessor member functions */
    int get_id() const;
    const char* get_name() const;
    float check_balance() const;

    /* Mutator member functions */
    void set_id(int new_id);
    void set_name(const char* new_name);
    void deposit(float amount);
    bool withdraw(float amount);
};
