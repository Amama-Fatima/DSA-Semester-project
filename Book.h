// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "GenreHash.h"


using namespace std;
struct Book {
    int id;
    string bookId;
    string title;
    string series;
    string author;
    double rating;
    string description;
    string language;
    vector<Genre> genres;
    vector<string> characters;
    string bookFormat;
    double pages;
    string publisher;
    string firstPublishDate;
    string awards;
    int likedPercent;
    string setting;
    string coverImg;
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
    Book(int id, string bId, string t, string ser, string auth, double rat,
         string desc, string lang, vector<Genre> gen, vector<string> chars,
         string format, double pg, string pub, string firstPub,
         string awd, int liked, string sett, string cover, double pr)
        : id(id), bookId(bId), title(t), series(ser), author(auth), rating(rat),
          description(desc), language(lang), genres(gen), characters(chars),
          bookFormat(format), pages(pg), publisher(pub), firstPublishDate(firstPub),
          awards(awd), likedPercent(liked), setting(sett), coverImg(cover), price(pr), right(NULL), left(NULL){}
};

Book* insertBook(Book* &head, int id, string bookId, string title, string series, string author, double rating,
                string description, string language, const vector<string>& genres, 
                const vector<string>& characters, string bookFormat, double pages, 
                string publisher, string firstPublishDate, string awards, int likedPercent, 
                string setting, string coverImg, double price);
void printBook(Book* head);
void viewBook(const Book* book);


#endif // BOOK_H