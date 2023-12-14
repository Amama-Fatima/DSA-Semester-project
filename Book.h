// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>



struct Book {
    std::string bookId;
    std::string title;
    std::string series;
    std::string author;
    double rating;
    std::string description;
    std::string language;
    std::vector<std::string> genres;
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

    // Pointer to the next book in a linked list (if you're using one)
    Book* next;

    // Constructor to initialize a Book object
    Book(std::string id, std::string t, std::string ser, std::string auth, double rat,
         std::string desc, std::string lang, std::vector<std::string> gen, std::vector<std::string> chars,
         std::string format, double pg, std::string pub, std::string firstPub,
         std::string awd, int liked, std::string sett, std::string cover, double pr)
        : bookId(id), title(t), series(ser), author(auth), rating(rat),
          description(desc), language(lang), genres(gen), characters(chars),
          bookFormat(format), pages(pg), publisher(pub), firstPublishDate(firstPub),
          awards(awd), likedPercent(liked), setting(sett), coverImg(cover), price(pr), next(nullptr) {}
};


#endif // BOOK_H