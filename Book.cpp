#include <iostream>
#include <fstream>
#include <sstream>

struct Book{
    int rank;
    string title;
    double price;
    double rating;
    string author;
    int yearOfPublication;
    string genre;
    string url;
    Book* next;
};

void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url);
void printBook(Book* head);


int main (){
    const int MAX_BOOKS = 100;
    Book* head = NULL;

    ifstream file('Top-100 Trending Books.csv');
    if (!file.is_open()){
        cout << "Error: File not found" << endl;
        return 0;
    }

    string line;
    getline(file, line); //skip the first line;
    while(getline(file, line)){
        stringstream sstream(line);
        int rank;
        string title;
        double price;
        double rating;
        string author;
        int yearOfPublication;
        string genre;
        string url;

        getline(sstream, field, ',');
        rank = stoi(field);

        getline(sstream, title, ',');

        getline(sstream, field, ',');
        price = stod(field);

        getline(sstream, field, ',');
        rating = stod(field);

        getline(sstream, author, ',');

        getline(sstream, field, ',');
        yearOfPublication = stoi(field);

        getline(sstream, genre, ',');

        getline(sstream, url, ',');

        insertBook(head, rank, title, price, rating, author, yearOfPublication, genre, url);

        file.close();

        printBook(head);
        return 0;
    }
}




void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url){
    Book* newBook = new Book;
    newBook->rank = rank;
    newBook->title = title;
    newBook->price = price;
    newBook->rating = rating;
    newBook->author = author;
    newBook->yearOfPublication = yearOfPublication;
    newBook->genre = genre;
    newBook->url = url;
    newBook->next = NULL;

    newBook->next = head;
    head = newBook;
}
    

void printBook(Book* head){
    Book* current = head;
    while(current != NULL){
        cout << current->rank << endl;
        cout << current->title << endl;
        cout << current->price << endl;
        cout << current->rating << endl;
        cout << current->author << endl;
        cout << current->yearOfPublication << endl;
        cout << current->genre << endl;
        cout << current->url << endl;
        current = current->next;
    }
}



