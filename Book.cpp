#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "BookFunctions.h"

using namespace std;

extern int last_rank;


void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url, string description);
void printBook(Book* head);



void insertBook(Book* &head, std::string bookId, std::string title, std::string series, std::string author, double rating,
                std::string description, std::string language, const std::vector<std::string>& genres, 
                const std::vector<std::string>& characters, std::string bookFormat, double pages, 
                std::string publisher, std::string firstPublishDate, std::string awards, int likedPercent, 
                std::string setting, std::string coverImg, double price) {
    
    Book* newBook = new Book(bookId, title, series, author, rating, description, language, genres, characters, 
                             bookFormat, pages, publisher, firstPublishDate, awards, likedPercent, setting, 
                             coverImg, price);
    
    if (head == nullptr) {
        // If the list is empty, make newBook the head
        head = newBook;
    } else {
        // Otherwise, find the last node and insert the newBook after it
        Book* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newBook;
    }
}

void printBook(const Book* book) {
    if (book != nullptr) {
        cout << "Book ID: " << book->bookId << endl;
        cout << "Title: " << book->title << endl;
        cout << "Author: " << book->author << endl;
        cout << "Rating: " << book->rating << endl;
        cout << "Price: " << book->price << endl;
    } else {
        cout << "No book to display." << endl;
    }
}


void viewBook(const Book* book) {
    if (book == nullptr) {
        cout << "No book to display." << endl;
        return;
    }

    cout << "Book ID: " << book->bookId << endl;
    cout << "Title: " << book->title << endl;
    cout << "Series: " << book->series << endl;
    cout << "Author: " << book->author << endl;
    cout << "Rating: " << book->rating << endl;
    cout << "Description: " << book->description << endl;
    cout << "Language: " << book->language << endl;
    cout << "Genres: ";
    for (const auto& genre : book->genres) {
        cout << genre << "; ";
    }
    cout << endl;
    cout << "Characters: ";
    for (const auto& character : book->characters) {
        cout << character << "; ";
    }
    cout << endl;
    cout << "Book Format: " << book->bookFormat << endl;
    cout << "Pages: " << book->pages << endl;
    cout << "Publisher: " << book->publisher << endl;
    cout << "First Publish Date: " << book->firstPublishDate << endl;
    cout << "Awards: " << book->awards << endl;
    cout << "Liked Percent: " << book->likedPercent << endl;
    cout << "Setting: " << book->setting << endl;
    cout << "Cover Image URL: " << book->coverImg << endl;
    cout << "Price: " << book->price << endl;
}


