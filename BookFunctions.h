// BookFunctions.h
#ifndef BOOKFUNCTIONS_H
#define BOOKFUNCTIONS_H

#include "Book.h"
using namespace std;
// Function declarations
void insertBook(Book* &head, string bookId, string title, string series, string author, double rating,
                string description, string language, const vector<std::string>& genres, 
                const vector<std::string>& characters, string bookFormat, double pages, 
                string publisher, string firstPublishDate, string awards, int likedPercent, 
                string setting, string coverImg, double price);
void printBook(Book* head);
void viewBook(const Book* book);

// ... any other function declarations ...

#endif // BOOKFUNCTIONS_H

