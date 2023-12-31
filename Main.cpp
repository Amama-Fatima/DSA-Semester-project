#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "BookFunctions.h"
#include "Book.h"
#include "Graph.h"
using namespace std;

string parseField(stringstream &sstream);
vector<string> parseList(const string &listStr);
GenreHashTable genreTable;
Graph bookGraph(0);

int main() {
    ifstream file("ReducedBooks.csv");
    if (!file.is_open()) {
        cerr << "Error: File not found" << endl;
        return 1;
    }

    string line;
    file.seekg(0);
    getline(file, line); // Read the first line (should be headers)
    Book* head = NULL;
    int idGenerated = 0;
    
    while (getline(file, line)) {
        idGenerated++;
        stringstream sstream(line);

        string bookId;
        string title;
        string series;
        string author;
        double rating;
        string description;
        string language;
        string genres;
        string characters;
        string bookFormat;
        double pages;
        string publisher;
        string firstPublishDate;
        string awards;
        int likedPercent;
        string setting;
        string coverImg;
        double price;

        bookId = parseField(sstream);
        title = parseField(sstream);
        series = parseField(sstream);
        author = parseField(sstream);
        
        try {
            rating = stod(parseField(sstream));
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stod with rating: '" << parseField(sstream) << "'" << endl;
            continue;
        }

        description = parseField(sstream);
        language = parseField(sstream);
        genres = parseField(sstream);
        // cout << "lineCount: " << lineCount << endl; // "lineCount: 1
        // cout << "Genres: " << genres << endl;
        characters = parseField(sstream);
        // cout << "Characters: " << characters << endl;
        bookFormat = parseField(sstream);

        // Try to convert pages
        try {
            pages = stod(parseField(sstream));
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stod with pages: '" << parseField(sstream) << "'" << endl;
            cout << "Book id: " << bookId << endl;
            continue;
        }

        publisher = parseField(sstream);
        firstPublishDate = parseField(sstream);
        awards = parseField(sstream);

        // Try to convert likedPercent
        try {
            likedPercent = stoi(parseField(sstream));
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stoi with likedPercent: '" << parseField(sstream) << "'" << endl;
            continue;
        }

        setting = parseField(sstream);
        coverImg = parseField(sstream);

        string priceStr = parseField(sstream);  
        try {
            if (!priceStr.empty()) {
                price = stod(priceStr);  
            } else {
                price = 0.0;  
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stod with priceStr: '" << priceStr << "'" << endl;
            price = 0.0;  
        }

        vector<string> bookGenres = parseList(genres);
        vector<string> bookCharacters = parseList(characters);

        insertBook(head, idGenerated, bookId, title, series, author, rating, description, language, bookGenres, bookCharacters, bookFormat, pages, publisher, firstPublishDate, awards, likedPercent, setting, coverImg, price);
    }

    file.close();

    return 0;
}
string parseField(stringstream &sstream) {
    string field;
    char peekChar = sstream.peek();
    if (peekChar == '"') {
        
        sstream.get();
        while(true) {
            string part;
            
            std::getline(sstream, part, '"');
            field += part;
            
            if (sstream.peek() == '"') {
        
                field += '"';
                
                sstream.get();
            } else {
        
                break;
            }
        }
        
        if (sstream.peek() == ',') {
            sstream.ignore();
        }
    } else {
        std::getline(sstream, field, ',');
    }
    return field;
}


vector<string> parseList(const string &listStr){
    vector<string> result;
    istringstream ss(listStr);
    char openBracket, closeBracket;

    ss >> openBracket;

    string token;
    while(getline(ss, token, ',')){
        
        size_t start = token.find_first_not_of(" \t");
        size_t end = token.find_last_not_of(" \t");
        if(start != string::npos && end != string::npos){
            result.push_back(token.substr(start, end-start+1));
        }
    }

    ss >> closeBracket;
    return result;
}


