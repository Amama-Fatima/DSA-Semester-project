// BookFunctions.h
#ifndef BOOKFUNCTIONS_H
#define BOOKFUNCTIONS_H

#include "Book.h"

// Function declarations
void insertBook(Book* &head, std::string bookId, std::string title, std::string series, std::string author, double rating,
                std::string description, std::string language, const std::vector<std::string>& genres, 
                const std::vector<std::string>& characters, std::string bookFormat, double pages, 
                std::string publisher, std::string firstPublishDate, std::string awards, int likedPercent, 
                std::string setting, std::string coverImg, double price);
void printBook(Book* head);
void viewBook(const Book* book);

// ... any other function declarations ...

#endif // BOOKFUNCTIONS_H

