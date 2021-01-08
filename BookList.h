#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"

class BookList{
private:
     Book* books;
     int capacity;
     int booksCount;
public:
     static int count2; // I used it to know the size of array that returned from getBooksForUser
     BookList(); // Default constructor
     void setcapacity(int capacity); // to set Capacity
     BookList(const BookList& anotherList);
     BookList(int capacity);
     Book* searchBook(string name);
     Book* searchBook(int id);
     void deleteBook(int id); //delete a book
     Book* getTheHighestRatedBook();
     Book* getBooksForUser(User); // get all books of this author
     Book & operator [ ] (int position);
     friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
     ~BookList();
};

#endif // BOOKLIST_H
