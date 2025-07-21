
// Library Book Tracker in C++ using DSA (Linked List)
// Developed for Cipher School by Tejaswi Pratap

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;
    Book* next;
};

class Library {
private:
    Book* head;
    int nextId;

public:
    Library() {
        head = nullptr;
        nextId = 1;
    }

    void addBook(string title, string author) {
        Book* newBook = new Book;
        newBook->id = nextId++;
        newBook->title = title;
        newBook->author = author;
        newBook->isBorrowed = false;
        newBook->next = head;
        head = newBook;
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        Book* temp = head;
        if (!temp) {
            cout << "No books available.\n";
            return;
        }
        while (temp) {
            cout << "\nID: " << temp->id << "\nTitle: " << temp->title << "\nAuthor: " << temp->author;
            cout << "\nStatus: " << (temp->isBorrowed ? "Borrowed" : "Available") << "\n";
            temp = temp->next;
        }
    }

    void searchBook(string keyword) {
        Book* temp = head;
        bool found = false;
        while (temp) {
            if (temp->title.find(keyword) != string::npos || temp->author.find(keyword) != string::npos) {
                cout << "\nID: " << temp->id << "\nTitle: " << temp->title << "\nAuthor: " << temp->author;
                cout << "\nStatus: " << (temp->isBorrowed ? "Borrowed" : "Available") << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No matching book found.\n";
    }

    void borrowBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (!temp->isBorrowed) {
                    temp->isBorrowed = true;
                    cout << "Book borrowed successfully.\n";
                } else {
                    cout << "Book is already borrowed.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Book ID not found.\n";
    }

    void returnBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (temp->isBorrowed) {
                    temp->isBorrowed = false;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not borrowed.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Book ID not found.\n";
    }

    void deleteBook(int id) {
        Book* temp = head;
        Book* prev = nullptr;

        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Book not found.\n";
            return;
        }

        if (!prev) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Book deleted successfully.\n";
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author, keyword;

    do {
        cout << "\n===== Library Book Tracker =====\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Borrow Book\n5. Return Book\n6. Delete Book\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            lib.addBook(title, author);
            break;
        case 2:
            lib.displayBooks();
            break;
        case 3:
            cout << "Enter keyword to search: ";
            getline(cin, keyword);
            lib.searchBook(keyword);
            break;
        case 4:
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            lib.borrowBook(id);
            break;
        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            break;
        case 6:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            lib.deleteBook(id);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
