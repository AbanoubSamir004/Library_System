#include "UserList.h"

UserList::UserList(){
    capacity=0;
    usersCount=0;
}

UserList::UserList(int capacity){
    this->capacity=capacity;
    users = new User[capacity];
    usersCount=0;
}

void UserList:: setcapacity(int siz){
    this->capacity=siz;
    users = new User[siz];
    usersCount=0;
}

void UserList:: addUser(User user){
    if (usersCount==capacity){  // Incase of maximum capacity.
        cout<<"Maximum Capacity"<<endl;
        exit(0);
    }
    users[usersCount]=user;
    usersCount++;
}

User* UserList:: searchUser(string name){
    for (int i=0;i<usersCount;i++){
        if (users[i].name==name){
            return  &users[i];
        }
    }
    return NULL;
}

User* UserList:: searchUser(int id){
    for (int i=0;i<usersCount;i++){
        if (users[i].id==id){
            return &users[i];
        }
    }
    return NULL;
}

void UserList:: deleteUser(int id){
     int q=0;
    for(int i=0 ;i<usersCount ;i++)
    {
        if(users[i].id==id){
            q=i;
            break;
            }
    }
    for(int i=q;i<usersCount-1 ;i++){

        if(q==usersCount-1)
            break;
        users[i]=users[i+1];
    }
    usersCount--;
}

ostream &operator<<(ostream &output, UserList &userList){
    for (int i=0;i<userList.usersCount;i++){
        output << "========User " << userList.users[i].getidOrder() << " info=======" << "\n";
        output<<userList.users[i]<<endl;
    }
    return output;
}

UserList::~UserList(){
    delete []users;
}

