#ifndef CART_H
#define CART_H

#include <iostream>
#include <stack>
#include "Book.h" 

using namespace std;

class Cart {
private:
    stack<Book> books;

public:
    // Add a book to the cart
    void addToCart(const Book& book) {
        books.push(book);
        cout << "Book added to the cart: " << book.title << endl;
    }

    // Remove the latest added book from the cart
    void removeFromCart() {
        if (!books.empty()) {
            Book latestBook = books.top();
            books.pop();
            cout << "Latest book removed from the cart: " << latestBook.title << endl;
        } else {
            cout << "Cart is empty. Cannot remove a book." << endl;
        }
    }

    // Display the contents of the cart
    void displayCart() const {
        if (books.empty()) {
            cout << "Cart is empty." << endl;
        } else {
            cout << "Books in the cart:" << endl;
            stack<Book> tempStack = books;

            while (!tempStack.empty()) {
                Book currentBook = tempStack.top();
                cout << currentBook.title << " - " << currentBook.price << endl;
                tempStack.pop();
            }
        }
    }
};
#endif // CART_H