#ifndef C___USER_H
#define C___USER_H
#include<cstring>
#include<iostream>
using namespace std;
class User
{
private:
    //private member variables of the User class
    string name;
    int age;
    int id;
    string password;
    string email;
    int idOrder; // to get the order of the user;
public:
    // static member variable that is incremeanted everytime an object is created.
    static int count;
    // Default costructor that have no arguments
    User();
    // parameterized constructor that accepts 4 arguments of datatype strings and integer.
    User(string name, int age, string email, string password);
    //copy constructor
    User(const User& user);
    //this function helps in comparing two objects if they are equal or not.
    bool operator==(const User& User);
    // setter that assigns the value of the argument sent by user to the name variable.
    void setName(string name);
    // getter that return the value in the name variable.
    string getName() ;
    // setter that assigns the value of the argument sent by user to the password variable.
    void setPassword(string password);
    // getter that return the value in the password variable.
    string getPassword() ;
    // setter that assigns the value of the argument sent by user to the email variable.
    void setEmail(string email);
    // getter that return the value in the email variable.
    string getEmail() ;
    // setter that assigns the value of the argument sent by user to the age variable.
    void setAge(int age);
    // getter that return the value in the age variable.
    int getAge() ;
    // setter that assigns the value of the argument sent by user to the id variable.
    void setId(int id);
    // getter that return the value in the id variable.
    int getId() ;
    // this function helps in printing an object as an output.
    friend ostream& operator<<(ostream& output, const User& user);
    // this function helps in taking an object as an input.
    friend istream& operator>>(istream& input, User& user);
    friend class UserList;
    void operator=(const User &user);
    int getidOrder(); // to get order of the user

};


#endif //C___USER_H
