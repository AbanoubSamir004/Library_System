#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;
class Book
{
private:
    //private member variables of the Book class
    string title;
    string isbn;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string category;
    int x=0;// this variable made to calculate the average rating
    int y=0;// this variable made to calculate the average rating
    // this variable should contain the average rating for the book, rateBook function
    // should update this attribute with the new average rating for the book
    double averageRating;
    //object of User class.
    User author;
public:
    // static member variable that is incremeanted everytime an object is created.
    static int count;
    // Default costructor that have no arguments.
    Book();
    // parameterized constructor that accepts 3 arguments of datatype strings.
    Book(string title, string isbn, string category);
    //copy constructor.
    Book(const Book& book);
    // setter that assigns the value of the argument sent by user to the title variable.
    void setTitle(string title);
    // getter that return the value in the title variable.
    string getTitle() ;
    // setter that assigns the value of the argument sent by user to the isbn variable.
    void setISBN(string isbn);
    // getter that return the value in the isbn variable.
    string getISBN() ;
    // setter that assigns the value of the argument sent by user to the id variable.
    void setId(int id);
    // getter that return the value in the id variable.
    int getId() ;
    // setter that assigns the value of the argument sent by user to the category variable.
    void setCategory(string category);
    // getter that return the value in the category variable.
    string getCategory() ;
    // setter that assigns the value of the argument sent by user which is an object of User class to the author variable.
    void setAuthor(User&user);
    // getter that return the value in the author object.
    User* getAuthor() ;
    // this function should update averageRating attribute as a new rating is
    // introduced to the book so the average rating should be affected.
    // Check the main screenshot to know more information
    void rateBook(int rating);
    //this function helps in comparing two objects if they are equal or not.
    bool operator==(const Book& book);
    // this function helps in printing an object as an output.
    friend ostream &operator<<(ostream &output, const Book &book );
    // this function helps in taking an object as an input.
    friend istream &operator>>( istream &input, Book &book );
    friend class BookList;
    void operator=(const Book &book);
};
#endif //C___BOOK_H

