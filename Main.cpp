#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
// #include <unordered_map>
#include "BookFunctions.h"
#include "Book.h"
// #include "Graph.h"
#include "AVL.h"
#include "Cart.h"
#include "bookheap.h" 
// #include "Prims.cpp"
#include "GraphAdj.h"
#include "DFS.h"
#include "BFS.h"
using namespace std;

string parseField(stringstream &sstream);
vector<string> parseList(const string &listStr);
int mainMenu(AVLTree priceTree, AVLTree pagesTree, AVLTree likedPercentTree, AVLTree idTree, Cart cart);
GenreHashTable genreTable;
GraphAdj bookAdjGraph(20);

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
    // unordered_map<string, BookHeap> genreHeaps;



    AVLTree priceTree;
    AVLTree pagesTree;
    AVLTree likedPercentTree;
    AVLTree idTree;
    Cart cart;

    
    while (getline(file, line) && idGenerated < 20) {
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
        characters = parseField(sstream);
        bookFormat = parseField(sstream);

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
        //also add genre to the hash table
        for (string genre: bookGenres) {
            genreTable.insertGenre(genre);
        }
        vector<string> bookCharacters = parseList(characters);

        
        Book* newBook = insertBook(head, idGenerated, bookId, title, series, author, rating, description, language, bookGenres, bookCharacters, bookFormat, pages, publisher, firstPublishDate, awards, likedPercent, setting, coverImg, price);
        priceTree.insertPrice(*newBook);
        pagesTree.insertPages(*newBook);
        likedPercentTree.insertLikedPercent(*newBook);
        idTree.insertId(*newBook);

    }

    file.close();
    createAdjacentGraph(head);
    cout << "After createAdjacentGraph" << endl;
    bookAdjGraph.generateDotFile("bookAdjGraph.dot");

    int i =0;
    while(true){
        mainMenu(priceTree, pagesTree, likedPercentTree, idTree, cart);
        i++;
        cout << "i: " << i << endl;
    }


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


int mainMenu(AVLTree priceTree, AVLTree pagesTree, AVLTree likedPercentTree, AVLTree idTree, Cart cart) {
    int choice;
    cout << "Welcome to the Book Recommendation System!" << endl;
    cout << "1. Search for a book" << endl;
    cout << "2. Go to cart" << endl;
    cout << "3. Give me recommendations" << endl;
    cout << "4. Check if genre exists" << endl;
    cout << "5. Perform DFS" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){

    //Search for a book
        case 1:
        {
            cout << "Search for book based on: " << endl;
            cout << "1. Price" << endl;
            cout << "2. Pages" << endl;
            cout << "3. Liked percent" << endl;

            int searchChoice;
            cout << "Enter your choice: ";
            cin >> searchChoice;

            switch(searchChoice){
                case 1:
                {
                    cout << "Enter the price range: " << endl;
                    double minPrice, maxPrice;
                    cout << "Enter the minimum price: ";
                    cin >> minPrice;
                    cout << "Enter the maximum price: ";
                    cin >> maxPrice;

                    vector<Book *> booksPrice = priceTree.searchPriceRange(minPrice, maxPrice);
                    cout << "Books found: " << endl;
                    for (int i = 0; i < booksPrice.size(); i++) {
                        cout << booksPrice[i]->title << endl;
                    }
                    break;
                }
                case 2:
                {

                    cout << "Enter the page range: " << endl;
                    double minPages, maxPages;
                    cout << "Enter the minimum pages: ";
                    cin >> minPages;
                    cout << "Enter the maximum pages: ";
                    cin >> maxPages;

                    vector<Book *> booksPages = pagesTree.searchPagesRange(minPages, maxPages);
                    cout << "Books found: " << endl;
                    for (int i = 0; i < booksPages.size(); i++) {
                        cout << booksPages[i]->title << endl;
                    }
                    break;
                }
                case 3:
                {

                    cout << "Enter the liked percent range: " << endl;
                    int minLikedPercent, maxLikedPercent;
                    cout << "Enter the minimum liked percent: ";
                    cin >> minLikedPercent;
                    cout << "Enter the maximum liked percent: ";
                    cin >> maxLikedPercent;

                    vector<Book *> booksLikedPercent = likedPercentTree.searchLikedPercentRange(minLikedPercent, maxLikedPercent);
                    cout << "Books found: " << endl;
                    for (int i = 0; i < booksLikedPercent.size(); i++) {
                        cout << booksLikedPercent[i]->title << endl;
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    // mainMenu();
                    break;
                }
            
            }
            break;
        }

        //Go to cart
        case 2:
        {
            // cartMenu();
            cout << "Choose an option: " << endl;
            cout << "1. Add a book to the cart" << endl;
            cout << "2. Remove the latest added book from the cart" << endl;
            cout << "3. Display the contents of the cart" << endl;

            int cartChoice;
            cout << "Enter your choice: ";
            cin >> cartChoice;
            switch(cartChoice){
                case 1:
                {
                    cout << "Enter the book id: ";
                    int bookId;
                    cin >> bookId;
                    Book *book = idTree.searchId(bookId);
                    cart.addToCart(*book);
                    break;
                }
                case 2:
                {

                    cart.removeFromCart();
                    break;
                }
                case 3:{

                    cart.displayCart();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    // mainMenu();
                    break;
                }
            }
            break;
        }

        //Give me recommendations
        case 3: 
        {   
            cout << "Give the id of the book for which you want recommendations: ";
            int bookId;
            cin >> bookId;

            primMST(bookAdjGraph.adjacencyMatrix, bookId, bookAdjGraph.numVertices);


            int* recBook;
            int input = 10;
            while(recBook[0]!=-1 && input == 10){
                recBook = recommendBook();
                if(recBook[0]!=-1){
                    Book* b = idTree.searchId(recBook[0]);
                    cout << "Recommendation: " << "id: "<< b->id << " Title: " << b->title << endl;
                }

                cout << "Enter 10 to recommend another book: " << endl;
                cin >> input;
             }


            break;
        }

        case 4:{
            cout << "Enter the genre you want to check: ";
            string genre;
            cin >> genre;
            
            if(genreTable.genreExists(genre)){
                cout << "Genre exists!" << endl;
            } else {
                cout << "Genre does not exist!" << endl;
            }
            genreTable.printTable();
            break;
        }

        case 5:{
            cout << "Enter the book id to start DFS and BFS: ";
            int bookId;
            cin >> bookId;
            cout << "Performing DFS: " << endl;
            DFS::performDFS(bookAdjGraph, bookId);
            cout << "Performing BFS: " << endl;
            BFS::performBFS(bookAdjGraph, bookId);
            break;
        }

        //Exit
        case 6:
        {

            cout << "Thank you for using the Book Recommendation System!" << endl;
            break;
        }
        default:
        {

            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    }
    return 0;
}


// dot -Tpng bookAdjGraph.dot -o bookAdjGraph.pn