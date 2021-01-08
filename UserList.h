#ifndef UNTITLED2_USERLIST_H
#define UNTITLED2_USERLIST_H
#include "User.h"

class UserList {
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList(); // Default constructor
    UserList(int capacity);
    void setcapacity(int siz); // to set the capacity of userlist
    void addUser(User user); // at the end of the array.
    User* searchUser(string name);
    User* searchUser(int id);
    void deleteUser(int id);
    friend ostream &operator<<( ostream &output, UserList &userList); //to display all books
    ~UserList();
};



#endif //UNTITLED2_USERLIST_H
