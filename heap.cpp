#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Book structure
class Book {
public:
    string bookId;
    string title;
    double rating;
    double price;
    string coverImg;

    // Constructor
    Book(string id, string t, double r, double p, string img) 
        : bookId(id), title(t), rating(r), price(p), coverImg(img) {}

    // Compare function for the priority queue
    bool operator<(const Book& b) const {
        return rating < b.rating;  // Max heap based on rating
    }
};

// Function to add a book to the priority queue
void addBook(priority_queue<Book>& pq, const string& bookId, const string& title, double rating, double price, const string& coverImg) {
    Book newBook(bookId, title, rating, price, coverImg);
    pq.push(newBook);
}

// Function to get the top recommended book
Book getTopRecommended(priority_queue<Book>& pq) {
    if (!pq.empty()) {
        Book topBook = pq.top();
        pq.pop();
        return topBook;
    } else {
        throw runtime_error("No books available for recommendation.");
    }
}

int main() {
    // Create a priority queue to store books
    priority_queue<Book> books;

    // Adding books to the priority queue
    addBook(books, "2767052-the-hunger-games", "The Hunger Games", 4.33, 5.09, "https://i.gr-assets.com/images/S/compressed.photo.goodreads.com/books/1586722975l/2767052.jpg");
    // Add more books similarly...

    try {
        // Get the top recommended book
        Book topBook = getTopRecommended(books);
        cout << "Top recommended book: " << topBook.title << " (Rating: " << topBook.rating << ")" << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
