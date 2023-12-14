#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "BookFunctions.h"
using namespace std;

string parseField(stringstream &sstream);

int main() {
    ifstream file("FinalBooks.csv");
    if (!file.is_open()) {
        cerr << "Error: File not found" << endl;
        return 1;
    }

    string line;
    file.seekg(0);
    getline(file, line); // Read the first line (should be headers)
    // cout << "Header Line: " << line << endl; // Print the header line

    // getline(file, line); // Read the second line (should be the first book)
    // cout << "First Book Line: " << line << endl; // Print the first book line

    // int totalLines = 0;
    // while (getline(file, line)) {
    //     totalLines++;
    // }
    // cout << "Total lines in the file: " << totalLines << endl;

    // // Reset and read again if needed
    // file.clear();
    // file.seekg(0);

    int lineNumber = 0;
    
    while (getline(file, line)) {
        lineNumber++;
        cout << "Processing line number: " << lineNumber << endl;
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

        // Try to convert rating
        try {
            rating = stod(parseField(sstream));
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument for stod with rating: '" << parseField(sstream) << "'" << endl;
            continue;
        }

        description = parseField(sstream);
        language = parseField(sstream);
        genres = parseField(sstream);
        characters = parseField(sstream);
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


