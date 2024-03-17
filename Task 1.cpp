#include <iostream>
#include <string>
#include <vector>

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
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }

    // Setters
    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setPublicationYear(int newYear) { publicationYear = newYear; }

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
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
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
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Book found:" << endl;
                book.display();
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library library;

    // Adding books to the library
    Book book1("As Good As Dead", "Holly Jackson", 2022);
    Book book2("The Silent Patient", "Alex Michaelides", 2021);
    Book book3("Twisted Games", "Ana Huang", 2019);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Display all books in the library
    library.listBooks();

    // Searching for a book
    cout << "\nSearching for 'The Silent Patient':" << endl;
    library.searchBook("The Silent Patient");

    // Removing a book
    library.removeBook("Twisted Games");
    cout << "\nAfter removing 'Twisted Games':" << endl;
    library.listBooks();

    return 0;
}
