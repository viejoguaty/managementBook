#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;
    string dateAdd;

public:
    // Constructor
    Book(
      string t = "", 
      string a = "", 
      string i = "", 
      bool avail = true, 
      string d = ""
    ) : 
      title(t),
      author(a),
      isbn(i),
      isAvailable(avail),
      dateAdd(d) {}

    // Set book details
    void setBookDetails(
      string t, 
      string a,
      string i, 
      bool avail,
      string d
    ) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = avail;
        dateAdd = d;
    }

    // Display book details
    void displayBookDetails() const {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "ISBN: " << isbn << "\n";
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << "\n";
    }

    // Borrow a book
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully!\n";
            return true;
        } else {
            cout << "Sorry: Book is already borrowed.\n";
            return false;
        }
    }

    // Return a book
    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully!\n";
    }

    // Get ISBN
    string getISBN() const { return isbn; }

    // Sort books by ISBN
    static void sortBookData(vector<Book>& library, int size) {
      // Bubble sort implementation
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (library[i].isbn > library[j].isbn) {
                  swap(library[i], library[j]);
                }
            }
        }
    }
};

//Method to add book
void addBook(vector<Book>& library) { 
  // Pass library by reference
  cout << "Add a book\n";
  string inputTitle, inputAuthor, inputISBN, inputDateAdd;
  cout << "Enter Title: ";
  cin >> inputTitle;
  cout << "Enter Author: "; 
  cin >> inputAuthor;
  cout << "Enter ISBN: ";
  cin >> inputISBN;
  cout << "Enter Date Add: ";
  cin >> inputDateAdd;  
  library.push_back(Book(inputTitle, inputAuthor, inputISBN, true, inputDateAdd));
  library.back().displayBookDetails();
  cout << "Book added successfully!\n";
}


int main() {
    // Initialize library with some books
    vector< Book > library = {
        Book("Harry Potter", "J.K. Rowling", "12345", true, "2024-01-10"),
        Book("Don Quixote", "Miguel de Cervantes Saavedra", "53456", true, "2024-02-15"),
        Book("The Lord of the Rings", "J.R.R. Tolkien", "45567", true, "2024-03-20"),
        Book("The Little Prince", "Antoine de Saint-Exupéry", "23678", true, "2024-04-25"),
        Book("A Tale of Two Cities", "Charles Dickens", "56789", true, "2024-05-30")
    };

   // User input for option
    int inputOptionInit;
    int getArrayLength = library.size();

      while (true) {
        // Display menu
        cout << "\n\n";
        cout << "Welcome to Library Management System\n";
        cout << "What do you want to do?\n";
        cout << "1. Add a book\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Diplay all Books\n";
        cin >> inputOptionInit;

        if (inputOptionInit == 1) {
            addBook(library);
        } else if (inputOptionInit == 2) {
          bool foundBook = false; // Flag to check if the book is found
          string inputISBN;

          // User input for ISBN
          cout << "Enter ISBN to borrow (0 to exit): ";
          cin >> inputISBN;

          
          // Exit condition if user inputs "0"
          if (inputISBN == "0") break;

          // Search for the book in the sorted array
          for (int i = 0; i < getArrayLength; ++i) {
              if (library[i].getISBN() == inputISBN) {
                    foundBook = true;
                  library[i].displayBookDetails();
                  library[i].borrowBook();
                  break;
              }
          }
          
          // If the book is not found
          if (!foundBook) {
              cout << "Error 404: Book not found.\n";
          }
          
        } else if (inputOptionInit == 3) {
          // Sort and display all books
          Book::sortBookData(library, getArrayLength);
          for (int i = 0; i < getArrayLength; ++i) {
              cout << "\n";
              library[i].displayBookDetails();
          }
        }
      }
  
      // End of program exepction
      cout << "Program ENDED.\n";
      return 0; 
}
