#include <iostream>
#include "UserList.h"
#include "BookList.h"
using namespace std;

int main()
{
    UserList U;
    BookList B;
    BookList newList;
    int counter=0;
    int c=0; // to count the current index of Books
    bool flag1=false,flag2=false; // To check if i joined Users and Books Menu or not
    while(true){
        cout<<"Select one of the following choices"<<endl;
        cout<<"1- Books Menu"<<endl;
        cout<<"2- Users Menu"<<endl;
        cout<<"3- Exit"<<endl;
        int n;
        cin>>n;
        if (n==1){
            if (flag2==false){
                cout<<"How many books will be added?"<<endl;
                int x;
                cin>>x;
                B.setcapacity(x);
                flag2=true;
            }
            while(true){
                cout<<"BOOK MENU"<<endl;
                cout<<"1- Create a book and add it to the list"<<endl;
                cout<<"2- Search for a book"<<endl;
                cout<<"3- Display all books (with book rating)"<<endl;
                cout<<"4- Get the highest rating book"<<endl;
                cout<<"5- Get all books of a user"<<endl;
                cout<<"6- Copy the current Book List to a new Book List and switch to it"<<endl;
                cout<<"7- Back to the main menu"<<endl;
                int y;
                cin>>y;
                if (y==1){
                    cin>>B[c];
                    while(true){
                        cout<<"1- Assign author"<<endl;
                        cout<<"2- Continue"<<endl;
                        int v;
                        cin>>v;
                        if (v == 1){
                            cout<<"Enter author (user) id"<<endl;
                            int id;
                            cin>>id;
                            User* user= U.searchUser(id);
                            if (user==NULL)
                                cout<<"No Author Found with id = "<<id<<endl;
                            else{
                                B[c].setAuthor(*user);
                                break;
                            }
                        }
                        else if (v==2)
                            break;
                    }
                    c++;
                }
                else if (y==2){
                    cout<<"SEARCH FOR A BOOK"<<endl;
                    cout<<"1- Search by name"<<endl;
                    cout<<"2- Search by ID"<<endl;
                    cout<<"3- Return to Books Menu"<<endl;
                    int z;
                    cin>>z;
                    if (z==1){
                        Book* b;
                        cout<<"Enter name"<<endl;
                        string name;
                        cin>>name;
                        b=B.searchBook(name);
                        if (b==NULL)
                            cout<<"Not Found"<<endl;
                        else{
                            cout<<*b;
                            cout<<"Author: "<<b->getAuthor()->getName()<<endl<<endl;
                            while(true){
                                cout<<"1- Update author"<<endl;
                                cout<<"2- Update name"<<endl;
                                cout<<"3- Update Category"<<endl;
                                cout<<"4- Delete book"<<endl;
                                cout<<"5- Rate book"<<endl;
                                cout<<"6- Get back to books menu"<<endl;
                                int Update;
                                cin>>Update;
                                if (Update==1){
                                    cout<<"Enter author (user) id"<<endl;
                                    int id;
                                    cin>>id;
                                    User* user=U.searchUser(id);
                                    b->setAuthor(*user);
                                }
                                else if (Update==2){
                                    cout<<"Enter name"<<endl;
                                    string name;
                                    cin>>name;
                                    b->setTitle(name);
                                }
                                else if (Update==3){
                                    cout<<"Enter Category"<<endl;
                                    string category;
                                    cin>>category;
                                    b->setCategory(category);
                                }
                                else if (Update==4){
                                    B.deleteBook(b->getId());
                                    c--;
                                    break;
                                }
                                else if (Update==5){
                                    cout<<"Enter Rating Value"<<endl;
                                    int rate;
                                    cin>>rate;
                                    b->rateBook(rate);
                                }
                                else if (Update==6)
                                    break;
                            }
                        }
                    }
                    else if(z==2){
                        Book* b;
                        cout<<"Enter ID"<<endl;
                        int id;
                        cin>>id;
                        b=B.searchBook(id);
                        if (b==NULL)
                            cout<<"Not Found"<<endl;
                        else{
                            cout<<*b;
                            cout<<"Author: "<<b->getAuthor()->getName()<<endl<<endl;
                            while(true){
                                cout<<"1- Update author"<<endl;
                                cout<<"2- Update name"<<endl;
                                cout<<"3- Update Category"<<endl;
                                cout<<"4- Delete book"<<endl;
                                cout<<"5- Rate book"<<endl;
                                cout<<"6- Get back to books menu"<<endl;
                                int Update;
                                cin>>Update;
                                if (Update==1){
                                    cout<<"Enter author (user) id"<<endl;
                                    int id;
                                    cin>>id;
                                    User* user=U.searchUser(id);
                                    b->setAuthor(*user);
                                }
                                else if (Update==2){
                                    cout<<"Enter name"<<endl;
                                    string name;
                                    cin>>name;
                                    b->setTitle(name);
                                }
                                else if (Update==3){
                                    cout<<"Enter Category"<<endl;
                                    string category;
                                    cin>>category;
                                    b->setCategory(category);
                                }
                                else if (Update==4){
                                    B.deleteBook(b->getId());
                                    c--;
                                    break;
                                }
                                else if (Update==5){
                                    cout<<"Enter Rating Value"<<endl;
                                    int rate;
                                    cin>>rate;
                                    b->rateBook(rate);
                                }
                                else if (Update==6)
                                    break;
                            }
                        }
                    }
                }
                else if (y==3){
                    if(counter==0)
                        cout<<B;
                    else{
                        BookList newList(B);
                        cout<<newList;
                    }
                }
                else if (y==4){
                    Book* b = B.getTheHighestRatedBook();
                    cout<<*b;
                    cout<< "======== Author Info =======" <<endl;
                    cout<< *(b->getAuthor());
                }
                else if (y==5){
                    cout<<"Enter User ID"<<endl;
                    int id;
                    cin>>id;
                    User* user=U.searchUser(id);
                    Book* book=B.getBooksForUser(*user);
                    int siz=BookList::count2;
                    for (int i=0;i<siz;i++){
                        cout<<book[i];
                        cout<<book[i].getAuthor()->getName()<<endl;
                    }
                }
                else if (y==6){
                    BookList newList(B);
                    cout<<"Copied Current List 2 Books to new list and switched to it"<<endl<<endl;
                    counter=1;
                }
                else if (y==7)
                    break;
            }
        }
        else if (n==2){
            if (flag1==false){
                cout<<"How many users will be added?"<<endl;
                int x;
                cin>>x;
                U.setcapacity(x);
                User::count=0;
                flag1=true;
            }
            while(true){
                cout<<"USERS MENU"<<endl;
                cout<<"1- Create a USER and add it to the list"<<endl;
                cout<<"2- Search for a user"<<endl;
                cout<<"3- Display all users"<<endl;
                cout<<"4- Back to the main menu"<<endl;
                int y;
                cin>>y;
                if (y==1){
                    User user;
                    cin>>user;
                    User::count--;
                    U.addUser(user);
                }
                else if (y==2){
                    while(true){
                        cout<<"SEARCH FOR USER"<<endl;
                        cout<<"1- Search by name"<<endl;
                        cout<<"2- Search by id"<<endl;
                        cout<<"3- Return to Users Menu"<<endl;
                        int z;
                        cin>>z;
                        if (z==1){
                            User* u;
                            cout<<"Enter Name"<<endl;
                            string name;
                            cin>>name;
                            u = U.searchUser(name);
                            if (u==NULL)
                                cout<<"Not Found"<<endl;
                            else{
                                cout << "========User " << u->getidOrder() << " info=======" << "\n";
                                cout<<*u<<endl;
                                cout<<"1- Delete User"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                int z;
                                cin>>z;
                                if (z==1)
                                    U.deleteUser((*u).getId());
                            }
                        }
                        else if(z==2){
                            User* u;
                            cout<<"Enter id"<<endl;
                            int id;
                            cin>>id;
                            u = U.searchUser(id);
                            if (u==NULL)
                                cout<<"Not Found"<<endl;
                            else{
                                cout << "========User " << u->getidOrder() << " info=======" << "\n";
                                cout<<*u<<endl;
                                cout<<"1- Delete User"<<endl;
                                cout<<"2- Return to Users Menu"<<endl;
                                int z;
                                cin>>z;
                                if (z==1)
                                    U.deleteUser((*u).getId());
                            }
                        }
                        else if (z==3)
                            break;
                    }
                }
                else if (y==3)
                    cout<<U;
                else
                    break;
            }
        }
        else if (n==3)
            break;
        else
            cout<<"Wrong choice"<<endl;
    }
    return 0;
}
