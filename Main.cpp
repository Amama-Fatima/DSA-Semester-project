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
Graph bookGraph(500);

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
    
    while (getline(file, line) && idGenerated < 501) {
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
    CreateGraph(head);
    cout << "After CreateGraph" << endl;
    bookGraph.generateDotFile("bookGraph.dot");
    // bookGraph.printGraph();
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


int mainMenu() {
    int choice;
    cout << "Welcome to the Book Recommendation System!" << endl;
    cout << "1. Search for a book" << endl;
    cout << "2. Go to cart" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice):

    //Search for a book
        case 1:
            cout << "Search for book based on: " << endl;
            cout << "1. Price" << endl;
            cout << "2. Pages" << endl;
            cout << "3. Liked percent" << endl;

            int searchChoice;
            cout << "Enter your choice: ";
            cin >> searchChoice;

            switch(searchChoice):
                case 1:
                    cout << "Enter the price range: " << endl;
                    double minPrice, maxPrice;
                    cout << "Enter the minimum price: ";
                    cin >> minPrice;
                    cout << "Enter the maximum price: ";
                    cin >> maxPrice;

                    // vector<Book> books = searchByPrice(minPrice, maxPrice);
                    // cout << "Books found: " << endl;
                    // for (int i = 0; i < books.size(); i++) {
                    //     cout << books[i].title << endl;
                    // }
                    break;
                case 2:
                    cout << "Enter the page range: " << endl;
                    double minPages, maxPages;
                    cout << "Enter the minimum pages: ";
                    cin >> minPages;
                    cout << "Enter the maximum pages: ";
                    cin >> maxPages;

                    // vector<Book> books = searchByPages(minPages, maxPages);
                    // cout << "Books found: " << endl;
                    // for (int i = 0; i < books.size(); i++) {
                    //     cout << books[i].title << endl;
                    // }
                    break;
                case 3:
                    cout << "Enter the liked percent range: " << endl;
                    int minLikedPercent, maxLikedPercent;
                    cout << "Enter the minimum liked percent: ";
                    cin >> minLikedPercent;
                    cout << "Enter the maximum liked percent: ";
                    cin >> maxLikedPercent;

                    // vector<Book> books = searchByLikedPercent(minLikedPercent, maxLikedPercent);
                    // cout << "Books found: " << endl;
                    // for (int i = 0; i < books.size(); i++) {
                    //     cout << books[i].title << endl;
                    // }
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    mainMenu();
                    break;


            break;

        //Go to cart
        case 2:
            // cartMenu();
            cout << "Choose an option: " << endl;
            cout << "1. Add a book to the cart" << endl;
            cout << "2. Remove the latest added book from the cart" << endl;
            cout << "3. Display the contents of the cart" << endl;

            int cartChoice;
            cout << "Enter your choice: ";
            cin >> cartChoice;
            switch(cartChoice):
                case 1:
                    cout << "Enter the book id: ";
                    int bookId;
                    cin >> bookId;
                    // Book book = searchById(bookId);
                    // addToCart(book);
                    break;
                case 2:
                    // removeFromCart();
                    break;
                case 3:
                    // displayCart();
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    mainMenu();
                    break;
            break;

        //Exit
        case 3:
            cout << "Thank you for using the Book Recommendation System!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            mainMenu();
            break;



    return 0;
}

