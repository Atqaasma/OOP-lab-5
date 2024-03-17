#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(const string& title, const string& author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear) {}

    // Getters
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }

    // Display book details
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
    // Add a book to the library
    void addBook(const Book& newBook) {
        books.push_back(newBook);
    }

    // Remove a book from the library based on title
    void removeBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getTitle() == title;
        });
        if (it != books.end()) {
            books.erase(it);
        }
    }

    // Display all books in the library
    void listBooks() const {
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            book.display();
            cout << endl;
        }
    }

    // Search for a book based on title
    void searchBook(const string& title) const {
        auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getTitle() == title;
        });
        if (it != books.end()) {
            cout << "Book found:" << endl;
            it->display();
        } else {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    // Creating a Library instance
    Library library;

    // Adding books to the library
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));
    library.addBook(Book("1984", "George Orwell", 1949));

    // Display all books in the library
    library.listBooks();

    // Searching for a book
    cout << "\nSearching for 'To Kill a Mockingbird':" << endl;
    library.searchBook("To Kill a Mockingbird");

    // Removing a book
    library.removeBook("1984");
    cout << "\nAfter removing '1984':" << endl;
    library.listBooks();

    return 0;
}
