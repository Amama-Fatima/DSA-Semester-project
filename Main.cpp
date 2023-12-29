#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "BookFunctions.h"
using namespace std;

string parseField(stringstream &sstream);

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

    while (getline(file, line)) {
        
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
        cout << "Genres: " << genres << endl;
        characters = parseField(sstream);
        cout << "Characters: " << characters << endl;
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

        string priceStr = parseField(sstream);  // Extract the price field as a string
        try {
            if (!priceStr.empty()) {
                price = stod(priceStr);  // Attempt to convert price to a double
            } else {
                price = 0.0;  // Set a default value if the string is empty
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stod with priceStr: '" << priceStr << "'" << endl;
            price = 0.0;  // Set to default value on error
        }

        vector<string> bookGenres = parseList(genres);
        vector<string> bookCharacters = parseList(characters);

        insertBook(head, bookId, title, series, author, rating, description, language, bookGenres, bookCharacters, bookFormat, pages, publisher, firstPublishDate, awards, likedPercent, setting, coverImg, price);
    }

    file.close();

    return 0;
}
string parseField(stringstream &sstream) {
    string field;
    char peekChar = sstream.peek();
    if (peekChar == '"') {
        // Consume the opening quote
        sstream.get();
        while(true) {
            string part;
            // Use std::getline to read until the next quote character
            std::getline(sstream, part, '"');
            field += part;
            // Check the next character after the quote
            if (sstream.peek() == '"') {
                // This is an escaped quote, add it to the field and continue
                field += '"';
                // Consume the escaped quote
                sstream.get();
            } else {
                // It's the end of the quoted field, break the loop
                break;
            }
        }
        // Discard the comma after the closing quote
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

    ss >> openBracket; // Read the opening bracket '['

    //read individual strings separated by commas
    string token;
    while(getline(ss, token, ',')){
        //remove the leading and trailing whitespaces
        size_t start = token.find_first_not_of(" \t");
        size_t end = token.find_last_not_of(" \t");
        if(start != string::npos && end != string::npos){
            result.push_back(token.substr(start, end-start+1));
        }
    }

    ss >> closeBracket; // Read the closing bracket ']'
    return result;
}

// string parseField(stringstream &sstream) {
//     string field;
//     char peekChar = sstream.peek();
//     if (peekChar == '"') {
//         // Consume the opening quote
//         sstream.get();
//         bool insideQuotes = true;
//         while(insideQuotes) {
//             string part;
//             // Use std::getline to read until the next quote character
//             std::getline(sstream, part, '"');
//             field += part;
//             // Check the next character after the quote
//             if (sstream.peek() == '"') {
//                 // This is an escaped quote, add it to the field and continue
//                 field += '"';
//                 // Consume the escaped quote
//                 sstream.get();
//             } else {
//                 // It's the end of the quoted field
//                 insideQuotes = false;
//             }
//         }
//         // Discard the comma after the closing quote
//         if (sstream.peek() == ',') {
//             sstream.ignore();
//         }
//     } else {
//         std::getline(sstream, field, ',');
//     }
//     return field;
// }


