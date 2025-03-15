/**
 * class should depend in interface rather than concrete class
 * abstraction should not depend on details . details should depend on abstraction 
 */

#include <iostream>
#include <string>


// class Database{
// public:
//     void saveUser(std::string& userName){
//         std::cout << "Saving user " << userName << " to the database." << std::endl;
//     }

//     void getUser(int id){
//         std::cout << "getting user with id : " << id << std :: endl; 
//     }
// };


// /**
//  * userservices class depend directly on Database class hence making it difficult to change database implementation 
//  * eg switching to different database  
//  */
// class UserServices{
//     Database db;
// public : 

//     void createUser(std :: string& uname){
//         db.saveUser(uname);
//     } 

//     void getUser(int id){
//         db.getUser(id);
//     }

// };

int main()
{

return 0;
}