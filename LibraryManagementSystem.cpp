#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:

    int bookId;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string title, string author) {
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display() {
        cout<< "BookID: " << bookId << endl;
        cout<< "Title: " << title << endl;
        cout << "Author: "<< author << endl;
        cout << "Is book issued? " << isIssued << endl;

    }

    void issueBook() {
        if (isIssued) {
            cout<< "Book already issued." << endl;
        } else {
            isIssued = true;
            cout << "Book is issued." << endl;
        }
    }

    void returnBook () {
        cout<< "Book is returned" << endl;
        isIssued = false;
    }
};

class Library {
public:

    vector<Book> books;

    void addBook(const Book &book) {
        books.push_back(book);
    }

    void searchBook (int bookId) {
        bool found = false;

        for(const Book &book : books) {
            if (book.bookId == bookId) {
                found = true;
                cout << "Book is available...";
                break;
            } 
        }
        if (!found) {
                cout<< "Book not found..";
            }
    }

    void issueBook(int bookId) {
        bool found = false;
        for(Book &book : books) {
            if (book.bookId == bookId) {
                found = true;
                book.issueBook();
                break;
            } 
        }

        if(!found) {
            cout << "Book not found" << endl;
        }
        
        
    }

    void returnBook(int bookid) {
        bool found = false;
        for(Book &book: books) {
            if(book.bookId == bookid) {
                found = true;
                if (book.isIssued) {
                        book.returnBook();
                    } else {
                        cout << "Book was never issued";
                    }
                    break;
                }
            }

        if (!found) {
            cout<< "Book not found";
        }

    }

    void removeBook (int bookId) {

        for (auto it = books.begin(); it!= books.end(); it++) {
            if(it->bookId == bookId) {
                books.erase(it);
                cout<< "Book removed"<< endl;
                return;
            }
        }

        cout << "Book not found" << endl;
    }

    void displayBooks() {
        cout << "Books in Library..." << endl;

        for (Book &book: books) {
            book.display();
            cout << endl;
        }
    }

};

int main () {

    Book b1(123, "Man vs Maths", "Ali Rehman");

    b1.issueBook();
    b1.issueBook();
    b1.display();
    b1.returnBook();
    b1.display();
}