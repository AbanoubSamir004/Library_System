#include "Book.h"
int Book::count = 0;
double x = 0, y = 0; //variables used to get the averageRating.
// assigns default values to the variables in the default constructor.
Book::Book()
{
    count++;
    title = "";
    isbn = "";
    category = "";
    id = count;
    averageRating = 0.0;
}
// assigns values of the arguments sent by user to the variables in the parameteriezd constructor.
Book::Book(string title, string isbn, string category)
{
    // static member variable that is incremeanted everytime when a parameteriezd object is created.
    count++;
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    // assigns the value of the count to the id variable.
    id = count;
    averageRating = 0.0;
}
//copy constructor.
Book::Book(const Book& book)
{
    count++;
    this->title = book.title;
    this->isbn = book.isbn;
    this->category = book.category;
    this->id = book.id;
    this->averageRating = book.averageRating;
}
// setter that assigns the value of the argument sent by user to the title variable.
void Book::setTitle(string title)
{
    this->title = title;
}
// getter that return the value in the title variable.
string Book::getTitle()
{
    return title;
}
// setter that assigns the value of the argument sent by user to the isbn variable.
void Book::setISBN(string isbn)
{
    this->isbn = isbn;
}
// getter that return the value in the isbn variable.
string Book::getISBN()
{
    return isbn;
}
// setter that assigns the value of the argument sent by user to the id variable.
void Book::setId(int id)
{
    this->id = id;
}
// getter that return the value in the id variable.
int Book::getId()
{
    return id;
}
// setter that assigns the value of the argument sent by user to the category variable.
void Book::setCategory(string category)
{
    this->category = category;
}
// getter that return the value in the category variable.
string Book::getCategory()
{
    return category;
}
// setter that assigns the value of the argument sent by user which is an object of User class to the author variable.
void Book::setAuthor(User& user)
{
    this->author = user;
}
// getter that return the value in the author object.
User* Book::getAuthor() {
    return &author;
}
// this function should update averageRating attribute as a new rating is
// introduced to the book so the average rating should be affected.
// Check the main screenshot to know more information

void Book::rateBook(int rating) {
    y+=rating;
    x++;
    averageRating=(double)y/x;
}
//this function helps in comparing two Book objects if they are equal or not.
bool Book::operator==(const Book &book) {
    if (title==book.title && category==book.category && isbn==book.isbn && id==book.id){
        return true;
    }
    return false;
}
// this function helps in printing an object as an output.
ostream &operator<<(ostream &output, const Book &book) {
    output << "========Book " << book.id << " info=======" << "\n";
    output << "Title: " << book.title <<endl;
    output<< "ISPN: " << book.isbn <<endl;
    output<< "Id: " << book.id << endl;
    output<< "category : " << book.category << endl;
    output << "Avg rating: "<< book.averageRating<<endl;
    return output;
}
// this function helps in taking an object as an input.
istream &operator>>(istream &input, Book &book) {
    cout<<"Enter the user information in this order"<<endl;
    cout<<"Title  ISBN  Category (Space separated)"<<endl;
    input>>book.title>>book.isbn>>book.category;
    cout<<endl;
    return input;
}

void Book::operator=(const Book &book){
    title=book.title;
    isbn=book.isbn;
    category=book.category;
    x=book.x;
    y=book.y;
    averageRating=book.averageRating;
    id=book.id;
    author=book.author;
    return;
}
