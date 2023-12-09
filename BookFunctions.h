// BookFunctions.h
#ifndef BOOKFUNCTIONS_H
#define BOOKFUNCTIONS_H

#include "Book.h"

void insertBook(Book* &head, int rank, std::string title, double price, double rating, std::string author, int yearOfPublication, std::string genre, std::string url, std::string description);
void printBooks(Book* head);
void addUserBook(Book* &head, const std::string& filename);

// ... any other function declarations ...

#endif // BOOKFUNCTIONS_H

