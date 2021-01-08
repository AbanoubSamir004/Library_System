#include "BookList.h"

int BookList::count2=0;

BookList::BookList(){
    capacity=0;
    booksCount=0;
}

void BookList:: setcapacity(int capacity){
    this->capacity=capacity;
    books = new Book[capacity];
}

BookList::BookList(const BookList& anotherlist){
    capacity=anotherlist.capacity;
    books=new Book[capacity];
    for (int i=0;i<capacity;i++){
        books[i]=anotherlist.books[i];
    }
    booksCount=anotherlist.booksCount;
}

BookList::BookList(int capacity){
    this->capacity=capacity;
    books=new Book[capacity];
    booksCount=0;
}

Book* BookList::searchBook(string name){
    for (int i=0;i<booksCount;i++){
            if (books[i].title==name){
                return &books[i];
            }
    }
    return NULL;
}

Book* BookList::searchBook(int id){
    for (int i=0;i<booksCount;i++){
        if (books[i].id==id){
            return &books[i];
        }
    }
    return NULL;
}

void BookList::deleteBook(int id){
    bool flag=false;
    for (int i=0;i<booksCount;i++){
        if (books[i].id==id){
            flag=true;
        }
        if (flag==true && i+1<booksCount){
            books[i]=books[i+1];
            books[i].id=i+1;
        }
    }
    if (flag==true){
        booksCount--;
    }
}

Book* BookList::getTheHighestRatedBook(){
    int maxAverage=-1,ind=-1;
    for (int i=0;i<booksCount;i++){
        if (books[i].averageRating > maxAverage){
            maxAverage=books[i].averageRating;
            ind=i;
        }
    }
    return &books[ind];
}

Book* BookList::getBooksForUser(User user){
    Book* booksOfUser;
    int x=0;
    for (int i=0;i<booksCount;i++){
        if (books[i].getAuthor()->getName() == user.getName()){
            x++;
        }
    }
    count2=x;
    booksOfUser=new Book[x];
    int ind=0;
    for (int i=0;i<booksCount;i++){
        if (books[i].getAuthor()->getName() == user.getName()){
            booksOfUser[ind]=books[i];
            ind++;
        }
    }
    return booksOfUser;
}

Book& BookList::operator[ ](int position){
    if (position>=0 && position<=booksCount){
        if (position==booksCount){
            booksCount++;
        }
        return books[position];
    }else{
        Book* n=NULL;
        return *(n);
    }
}

ostream &operator<<(ostream &output, BookList &bookList){
    for (int i=0;i<bookList.booksCount;i++){
        output<<bookList[i];
        if (bookList[i].getAuthor()->getName() != ""){
            output << "======== Author Info =======" << "\n";
            output<<*bookList[i].getAuthor()<<endl;
        }
    }
    return output;
}
BookList::~BookList(){
    delete []books;
}
