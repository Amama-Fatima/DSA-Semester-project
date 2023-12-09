#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "BookFunctions.h"
#include "ViewBook.h"
#include "WaitingList.h"

using namespace std;

int last_rank = 0;


string parseField(stringstream &sstream);
int main (){
    const int MAX_BOOKS = 100;
    Book* head = NULL;

    ifstream file("Book Data - Top-100 Trending Books with Descriptions.csv");
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
        string description;

        //WE ARE READING THE DATA FROM THE FILE AND STORING IT IN THE VARIABLES
        rank = stoi(parseField(sstream));
        cout << "Rank field: '" << rank << "'" << endl;


        title = parseField(sstream);

        price = stod(parseField(sstream));

        rating = stod(parseField(sstream));

        author = parseField(sstream);

        yearOfPublication = stoi(parseField(sstream));

        genre = parseField(sstream);

        url = parseField(sstream);

        description = parseField(sstream);
        cout << "\n";
        cout << "Description field: '" << description << "'" << endl;
        cout << "\n";

        last_rank = rank;

        insertBook(head, rank, title, price, rating, author, yearOfPublication, genre, url, description);

    }


    file.close();

    if(head!=NULL){
        cout << "Printing books..." << endl;
        printBooks(head);
    } else{
        cout << "No books to print." << endl;
    }

    int rankToView;
    cout << "Enter the rank of the book you want to view: ";
    cin >> rankToView;
    viewBook(head, rankToView);

    cout << "Enter the rank of the book you want to view: ";
    cin >> rankToView;
    viewBook(head, rankToView);

    showMostRecentlyViewedBook();


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