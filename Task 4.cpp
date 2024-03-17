#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the Book class and the Library class here

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(const string& title, const string& author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& newBook) {
        books.push_back(newBook);
    }

    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
    }

    void listBooks() const {
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            book.display();
            cout << endl;
        }
    }

    bool isEmpty() const {
        return books.empty();
    }
};

// Function to handle user interaction
void userInterface(Library& lib) {
    string command;

    while (true) {
        cout << "\nEnter command (add, remove, list, exit): ";
        getline(cin, command);

        if (command == "add") {
            string title, author;
            int year;

            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> year;
            cin.ignore();  // Consume the newline character

            lib.addBook(Book(title, author, year));
            cout << "Book added successfully." << endl;
        } else if (command == "remove") {
            if (lib.isEmpty()) {
                cout << "Library is empty." << endl;
            } else {
                string title;
                cout << "Enter title of the book to remove: ";
                getline(cin, title);
                lib.removeBook(title);
                cout << "Book removed successfully." << endl;
            }
        } else if (command == "list") {
            if (lib.isEmpty()) {
                cout << "Library is empty." << endl;
            } else {
                lib.listBooks();
            }
        } else if (command == "exit") {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}

int main() {
    Library myLibrary;
    userInterface(myLibrary);
    return 0;
}
