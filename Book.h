// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    int rank;
    std::string title;
    double price;
    double rating;
    std::string author;
    int yearOfPublication;
    std::string genre;
    std::string url;
    std::string description;
    Book* next;
};

#endif // BOOK_H