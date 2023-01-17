// Contains alogorithms for password encryption
#include <iostream>
#include <string>
using namespace std;

class Hash_Password
{
    private:
    string real_hashedPassword;
    string generated_hashedPassword; //To be gotten from the Hasher Function.
    string real_username;
    public:
    //To contain a hashing algorithm that stores a string in generated_hashedpassword
    static string Hasher(Security& user_account);

};

//Function to retrieve hashed password and username from file.
//And store them in the structure Account_Logging.
void Credential_Retrieval();


//Function to store and write a hashed password and username to a file.
//Writes each line with a password and the hashed password.
void Credential_Writing();


//Class Security will be an object through composition.
class Security
{
    private:
    string entered_password  , entered_username;
    friend class HashPassword; //The class to help with password encryption
    public:
    //Constructor to take passwords and usernames from user.
    Security(string user_name, string user_password)
    :entered_username(user_name),entered_password(user_password){}

    //To change password for current user.
    //Calls HashPassword::Hasher() method to generate a hashed password.
    //Calls Credential writing() to write new credentials to a file.
    void changePassword();

    //To be invoked on new account creation.
    //Calls HashPassword::Hasher() method to generate a hashed password.
    //Calls Credential_Writting() method to write the details to a file.
    static bool setNewPassword(string username,string password); 
};



class Account_Recovery : private Security  //inherits in its private Security details
{

};

class Lock_Account : public Account_Recovery //inherits in its public Account_Recovery(public)
{

};

//Structure to collect details of logging
struct Account_logging
{
    int attempts;  //When attempts excede 3 and status is false call lock account.
    bool logging_status; //Current logging status. returns true if successful password login.
    string real_hashedPassword; //Retrieved from the file.
    bool username_presence; //Presence of the entered User name.
};
