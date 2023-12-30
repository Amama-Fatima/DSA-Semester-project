// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "GenreHash.h"
struct Book {
    std::string bookId;
    std::string title;
    std::string series;
    std::string author;
    double rating;
    std::string description;
    std::string language;
    std::vector<Genre> genres;
    std::vector<std::string> characters;
    std::string bookFormat;
    double pages;
    std::string publisher;
    std::string firstPublishDate;
    std::string awards;
    int likedPercent;
    std::string setting;
    std::string coverImg;
    double price;


    Book* right;
    Book* left;
    int height = 0;

    //zero argument constructor
    Book() : bookId(""), title(""), series(""), author(""), rating(0.0),
             description(""), language(""), bookFormat(""), pages(0.0),
             publisher(""), firstPublishDate(""), awards(""), likedPercent(0),
             setting(""), coverImg(""), price(0.0), right(NULL), left(NULL){}

    // Constructor to initialize a Book object
    Book(std::string id, std::string t, std::string ser, std::string auth, double rat,
         std::string desc, std::string lang, std::vector<Genre> gen, std::vector<std::string> chars,
         std::string format, double pg, std::string pub, std::string firstPub,
         std::string awd, int liked, std::string sett, std::string cover, double pr)
        : bookId(id), title(t), series(ser), author(auth), rating(rat),
          description(desc), language(lang), genres(gen), characters(chars),
          bookFormat(format), pages(pg), publisher(pub), firstPublishDate(firstPub),
          awards(awd), likedPercent(liked), setting(sett), coverImg(cover), price(pr), right(NULL), left(NULL){}
};


#endif // BOOK_H