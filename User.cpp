 #include<iostream>
#include "User.h"
using namespace std;
int User::count = 0;
// assigns default values to the variables in the default constructor.
User::User()
{
    count++;
    name = "";
    age = 0;
    email = "";
    password = "";
    id = count;
    idOrder=count;

}
// assigns values of the arguments sent by user to the variables in the parameteriezd constructor.
User::User(string name, int age, string email, string password)
{
    // static member variable that is incremeanted everytime when a parameteriezd object is created.
    count++;
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
    // assigns the value of the count to the id variable.
    id = count;
    idOrder=count;

}
//copy constructor.
User::User(const User& user)
{
    count++;
    this->name = user.name;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->id = user.id;
    idOrder=count;

}

// setter that assigns the value of the argument sent by user to the name variable.
void User::setName(string name)
{
    this->name = name;
}
// getter that return the value in the name variable.
string User::getName()
{
    return name;
}
// setter that assigns the value of the argument sent by user to the password variable.
void User::setPassword(string password)
{
    this->password = password;
}
// getter that return the value in the password variable.
string User::getPassword()
{
    return password;
}
// setter that assigns the value of the argument sent by user to the email variable.
void User::setEmail(string email)
{
    this->email = email;
}
// getter that return the value in the email variable.
string User::getEmail()
{
    return email;
}
// setter that assigns the value of the argument sent by user to the age variable.
void User::setAge(int age)
{
    this->age = age;
}
// getter that return the value in the age variable.
int User::getAge()
{
    return age;
}
// setter that assigns the value of the argument sent by user to the id variable.
void User::setId(int id)
{
    this->id = id;
}
// getter that return the value in the id variable.
int User::getId()
{
    return id;
};
//this function helps in comparing two Book objects if they are equal or not.
bool User:: operator==(const User& user)
{
    if (this->name == user.name && this->age == user.age && this->email == user.email && this->password == user.password && this->id == user.id)
        return true;
    else
        return false;
}
// this function helps in printing an object as an output.
ostream& operator<<(ostream& output, const User& obj)
{

    output << "Name: " << obj.name <<endl;
    output << "Age: " << obj.age <<endl;
    output << "Id: " << obj.id <<endl;
    output<< "Email:" << obj.email <<endl;
    output<< "==========================================" <<endl;
    return output;
}
// this function helps in taking an object as an input.
istream& operator>>(istream& input, User& obj) {
    cout<<"Enter the user information in this order"<<endl;
    cout<<"Name Age Email Password (Space separated)"<<endl;
    input >> obj.name >> obj.age >> obj.email >> obj.password;
    cout << endl;
    return input;
}

void User::operator=(const User &user){
    name=user.name;
    age=user.age;
    password=user.password;
    email=user.email;
    id=user.id;
    return;
}

int User::getidOrder(){
    return idOrder;
}
