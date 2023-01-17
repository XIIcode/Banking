#include <iostream>
#include <string>
#include "security.h"
using namespace std;
class UserAccount  //Base class.
{
    protected:
    string full_name,email_address,phone_number;
    bool employed;
    public:
    UserAccount(string user_fn , string user_emaddr , string user_pn ,bool user_employed)
    :full_name(user_fn),email_address(user_emaddr),phone_number(user_pn),employed(user_employed)
    {}
    virtual void withdraw() = 0; //To be implemented in the derived classes.
    virtual void deposit() = 0; //To be implemented in the derived classes.
    void delete_Account(); //To delete all details associated with the account.
    bool access_to_account; //if false user can not access the specified Account.
};

class CurrentAccount : private UserAccount
{
    private:
    int current_balance;

};

class FixedAccount : private UserAccount
{
    private:
    int fixed_balance;

};

class SavingsAccount : private UserAccount
{
    private:
    int savings_balance;

};

/*Asks user which type of account they want to create and creates an object for them.
using the Account constructor to set the details*/
//Calls Security::setnewpassword() to set the new password details of the account specified.
//After finishing a Success message is displayed.
void createAccount();

