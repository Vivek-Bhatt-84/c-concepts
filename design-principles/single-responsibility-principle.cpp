/**
 * class should have one reason to change
 */

#include <iostream>
using namespace std;

// class UserManager{
// public:
//     void registerUser(){

//     }

//     void senNotification(){

//     }
// };
// here usermanager class has 2 responsibilities 
// this violates (SRP) 

/**
 * corrected way
 * one class handles one responsibility 
 *  */

class userRegister{
public:
    void registerUser(){

    }
};

class NotificationSender{
public:
    void sendNotification(){

    }
};

int main()
{

return 0;
}