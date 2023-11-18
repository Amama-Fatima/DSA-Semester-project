#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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


string parseField(stringstream &sstream);
void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url);
void printBook(Book* head);


int main (){
    const int MAX_BOOKS = 100;
    Book* head = NULL;


    ///THIS PART IS FILE HANDLING. THE PROGRAM IS READING DATA FROM THE Book Data - Top-100 Trending Books.csv FILE. 
    ///IGNORE THIS CODE FOR NOW. WE WILL LEARN THAT TOMORROW
    ifstream file("Book Data - Top-100 Trending Books.csv");
    if (!file.is_open()){
        cout << "Error: File not found" << endl;
        return 0;
    }

    string line;
    getline(file, line); //skip the first line;

    while(getline(file, line)){
        //WHILE LOOP RUNS UNTIL THERE IS STILL A BOOK LEFT TO BE READ
        stringstream sstream(line);

        int rank;
        string title;
        double price;
        double rating;
        string author;
        int yearOfPublication;
        string genre;
        string url;

    //WE ARE READING THE DATA FROM THE FILE AND STORING IT IN THE VARIABLES
    rank = stoi(parseField(sstream));
    cout << "Rank field: '" << rank << "'" << endl;


    title = parseField(sstream);
    cout << "Title field: '" << title << "'" << endl;

    price = stod(parseField(sstream));
    cout << "Price: '" << price << "'" << endl;

    rating = stod(parseField(sstream));
    cout << "Rating: '" << rating << "'" << endl;

    author = parseField(sstream);
    cout << "Author field: '" << author << "'" << endl;

    yearOfPublication = stoi(parseField(sstream));
    cout << "Year of Publication: '" << yearOfPublication << "'" << endl;

    genre = parseField(sstream);
    cout << "Genre field: '" << genre << "'" << endl;

    url = parseField(sstream);
    cout << "URL field: '" << url << "'" << endl;


    insertBook(head, rank, title, price, rating, author, yearOfPublication, genre, url);

    }
    file.close();
    cout << "  " << endl;
    cout << "  " << endl;
    cout << "  " << endl;
    cout << "  " << endl;
    cout << " PRINTING BOOKS " << endl;
    cout << "  " << endl;
    cout << "  " << endl;
    printBook(head);

    cout << "Hello world" << endl;
    return 0;
}

string parseField(stringstream &sstream){
        string field;
        char peekChar = sstream.peek();
        if(peekChar == '"'){
            getline(sstream, field, '"');
            getline(sstream, field, '"');
            sstream.ignore(1, ',');
        } else{
            getline(sstream, field, ',');
        }
        return field;
    }


void insertBook(Book* &head, int rank, string title, double price, double rating, string author, int yearOfPublication, string genre, string url) {
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



