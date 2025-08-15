#include<iostream>
using namespace std;

class LibraryItem {
public:
    virtual void display() const = 0; 
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() : title(""), author(""), pages(0) {}
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    void display() const override {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }

    string getTitle() const { return title; }
    int getPages() const { return pages; }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() : name(""), date(""), edition("") {}
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}

    void display() const override {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }

    string getName() const { return name; }
    string getEdition() const { return edition; }
};

class Library {
private:
    static const int MAX_SIZE = 10; 
    Book books[MAX_SIZE];
    Newspaper newspapers[MAX_SIZE];
    int bookCount, newspaperCount;

public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < MAX_SIZE) {
            books[bookCount++] = book;
        }
        else {
            cout << "Book list is full!" << endl;
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (newspaperCount < MAX_SIZE) {
            newspapers[newspaperCount++] = newspaper;
        }
        else {
            cout << "Newspaper list is full!" << endl;
        }
    }

    void displayCollection() const {
        cout << endl << "Books in Library: "<<endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }

        cout << endl<<"Newspapers in Library: "<<endl;
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getName() == name) {
                return &newspapers[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Book book1("Stranger Things", "Mr.Frenzy", 250);
    Book book2("To Kill a Mockingbird", "Hammer", 340);

    Newspaper newspaper1("lahore News", "2025-03-25", "Morning Edition");
    Newspaper newspaper2("Jang Paper", "2024-03-25", "Weekend Edition");

    Library library;

    library.addBook(book2);
    library.addBook(book1);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "______Before Sorting______" << endl ;
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << endl<< "______After Sorting______"<<endl;
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << endl<<"Found Book:"<< endl;
        foundBook->display();
    }
    else {
        cout << endl << "Book not found."<< endl;
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout<< endl << "Found Newspaper: "<< endl;
        foundNewspaper->display();
    }
    else {
        cout<< endl << "Newspaper not found."<< endl;
    }

    return 0;
}