#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);
    std::string line1, line2;
    bool identical = true;

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    int lineNumber = 1;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            std::cout << "Difference found at line " << lineNumber << ":\n";
            std::cout << "File 1: " << line1 << "\nFile 2: " << line2 << "\n";
            identical = false;
        }
        lineNumber++;
    }

    while (getline(f1, line1)) {
        std::cout << "File 1 has extra line at " << lineNumber << ": " << line1 << "\n";
        identical = false;
        lineNumber++;
    }

    while (getline(f2, line2)) {
        std::cout << "File 2 has extra line at " << lineNumber << ": " << line2 << "\n";
        identical = false;
        lineNumber++;
    }

    if (identical) {
        std::cout << "Files are identical." << std::endl;
    }
}

int main() {
    compareFiles("file1.txt", "file2.txt");
    return 0;
}
#include <iostream>
#include <fstream>
#include <cctype>

void fileStatistics(const std::string& filename) {
    std::ifstream file(filename);
    std::ofstream output("statistics.txt");

    if (!file.is_open() || !output.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    char ch;
    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;

    while (file.get(ch)) {
        charCount++;

        if (std::isalpha(ch)) {
            char lowerCh = std::tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u' || lowerCh == 'y')
                vowelCount++;
            else
                consonantCount++;
        }
        else if (std::isdigit(ch)) {
            digitCount++;
        }

        if (ch == '\n') {
            lineCount++;
        }
    }

    output << "Characters: " << charCount << "\n";
    output << "Lines: " << lineCount + 1 << "\n"; 
    output << "Vowels: " << vowelCount << "\n";
    output << "Consonants: " << consonantCount << "\n";
    output << "Digits: " << digitCount << "\n";

    std::cout << "Statistics written to statistics.txt" << std::endl;
}

int main() {
    fileStatistics("file.txt");
    return 0;
}
#include <iostream>
#include <string>

std::string caesarCipher(const std::string& text, int shift) {
    std::string result = "";
    for (char ch : text) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            result += char(int(base + (ch - base + shift) % 26));
        }
        else {
            result += ch;  
        }
    }
    return result;
}

int main() {
    std::string text;
    int shift;

    std::cout << "Enter text: ";
    std::getline(std::cin, text);
    std::cout << "Enter shift value: ";
    std::cin >> shift;

    std::string encryptedText = caesarCipher(text, shift);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

void printBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Book " << i + 1 << ": \n";
        std::cout << "Title: " << books[i].title << "\n";
        std::cout << "Author: " << books[i].author << "\n";
        std::cout << "Publisher: " << books[i].publisher << "\n";
        std::cout << "Genre: " << books[i].genre << "\n\n";
    }
}

void editBook(Book& book) {
    std::cout << "Editing book: " << book.title << "\n";
    std::cout << "Enter new title: ";
    std::getline(std::cin, book.title);
    std::cout << "Enter new author: ";
    std::getline(std::cin, book.author);
    std::cout << "Enter new publisher: ";
    std::getline(std::cin, book.publisher);
    std::cout << "Enter new genre: ";
    std::getline(std::cin, book.genre);
    std::cout << "Book updated.\n";
}

void searchByAuthor(Book books[], int size, const std::string& author) {
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            std::cout << "Found book by author " << author << ":\n";
            std::cout << "Title: " << books[i].title << "\n";
            std::cout << "Publisher: " << books[i].publisher << "\n";
            std::cout << "Genre: " << books[i].genre << "\n\n";
        }
    }
}

void searchByTitle(Book books[], int size, const std::string& title) {
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            std::cout << "Found book with title " << title << ":\n";
            std::cout << "Author: " << books[i].author << "\n";
            std::cout << "Publisher: " << books[i].publisher << "\n";
            std::cout << "Genre: " << books[i].genre << "\n\n";
        }
    }
}

void sortByTitle(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    std::cout << "Books sorted by title.\n";
}

void sortByAuthor(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    std::cout << "Books sorted by author.\n";
}

void sortByPublisher(Book books[], int size) {
    std::sort(books, books + size, [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
    std::cout << "Books sorted by publisher.\n";
}

int main() {
    const int size = 10;
    Book books[size] = {
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Fiction"},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction"},
        {"Moby Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Fiction"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
        {"Brave New World", "Aldous Huxley", "Chatto & Windus", "Dystopian"},
        {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Psychological"}
    };

    int choice;
    std::string input;
    int bookIndex;

    do {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Print all books\n";
        std::cout << "2. Edit a book\n";
        std::cout << "3. Search by author\n";
        std::cout << "4. Search by title\n";
        std::cout << "5. Sort by title\n";
        std::cout << "6. Sort by author\n";
        std::cout << "7. Sort by publisher\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
        case 1:
            printBooks(books, size);
            break;
        case 2:
            std::cout << "Enter book index to edit (1-10): ";
            std::cin >> bookIndex;
            std::cin.ignore();
            if (bookIndex > 0 && bookIndex <= size) {
                editBook(books[bookIndex - 1]);
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        case 3:
            std::cout << "Enter author to search: ";
            std::getline(std::cin, input);
            searchByAuthor(books, size, input);
            break;
        case 4:
            std::cout << "Enter title to search: ";
            std::getline(std::cin, input);
            searchByTitle(books, size, input);
            break;
        case 5:
            sortByTitle(books, size);
            break;
        case 6:
            sortByAuthor(books, size);
            break;
        case 7:
            sortByPublisher(books, size);
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
