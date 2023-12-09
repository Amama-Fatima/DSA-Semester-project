#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "BookFunctions.h"

using namespace std;

extern int last_rank;


void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url, string description);
void printBooks(Book* head);



void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url, string description) {
    Book* newBook = new Book;
    newBook->rank = rank;
    newBook->title = title;
    newBook->price = price;
    newBook->rating = rating;
    newBook->author = author;
    newBook->yearOfPublication = yearOfPublication;
    newBook->genre = genre;
    newBook->url = url;
    newBook->description = description;
    newBook->next = NULL;

    if (head == NULL) {
        // If the list is empty, make newBook the head
        head = newBook;
    } else {
        // Otherwise, find the last node and insert the newBook after it
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }
}


void printBooks(Book* head){
    Book* current = head;
    while(current != NULL){

        cout << "Rank: " <<  current->rank << endl;
        cout << "Title: " << current->title << endl;
        cout << "Price: $" << current->price << endl;
        cout << "Rating: " << current->rating << " / 5" << endl;
        // cout << current->author << endl;
        // cout << current->yearOfPublication << endl;
        // cout << current->genre << endl;
        // cout << current->url << endl;
        cout << "\n";
        cout << "\n";
        current = current->next;
    }
}


void addUserBook(Book* &head, const string& filename){
    string title;
    double price;
    double rating;
    string author;
    int yearOfPublication;
    string genre;
    string url;
    string description;

    //Automatically assign the next rank
    int rank = ++last_rank;

    cout << "Enter the title of the book: ";
    getline(cin, title);

    cout << "Enter the price of the book: ";
    cin >> price;

    cout << "Enter the rating of the book: ";
    cin >> rating;

    cin.ignore();

    cout << "Enter the author of the book: ";
    getline(cin, author);

    cout << "Enter the year of publication of the book: ";
    cin >> yearOfPublication;

    cin.ignore();

    cout << "Enter the genre of the book: ";
    getline(cin, genre);

    cout << "Enter the url of the book: ";
    getline(cin, url);

    cout << "Enter the description of the book: ";
    getline(cin, description);

    insertBook(head, rank, title, price, rating, author, yearOfPublication, genre, url, description);

    ofstream file;
    file.open(filename, ios::app);
     if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    // Check if the file is empty. If not, start a new line before appending.
    // file.seekp(0, ios::end); // Move to the end of the file
    // if (file.tellp() != 0) {
    //     // File is not empty, start a new line
    //     file << "\n";
    // }

    file << rank << ","
         << "\"" << title << "\","
         << price << ","
         << rating << ","
         << "\"" << author << "\","
         << yearOfPublication << ","
         << "\"" << genre << "\","
         << "\"" << url << "\"\n";

    file.close();       
    cout << "Book added successfully with rank: " << rank << endl;

}


