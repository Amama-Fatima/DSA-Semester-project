#ifndef CART_H
#define CART_H

#include <iostream>
#include <stack>
#include "Book.h" 

class Cart {
private:
    std::stack<Book> books;

public:
    // Add a book to the cart
    void addToCart(const Book& book) {
        books.push(book);
        std::cout << "Book added to the cart: " << book.title << std::endl;
    }

    // Remove the latest added book from the cart
    void removeFromCart() {
        if (!books.empty()) {
            Book latestBook = books.top();
            books.pop();
            std::cout << "Latest book removed from the cart: " << latestBook.title << std::endl;
        } else {
            std::cout << "Cart is empty. Cannot remove a book." << std::endl;
        }
    }

    // Display the contents of the cart
    void displayCart() const {
        if (books.empty()) {
            std::cout << "Cart is empty." << std::endl;
        } else {
            std::cout << "Books in the cart:" << std::endl;
            std::stack<Book> tempStack = books;

            while (!tempStack.empty()) {
                Book currentBook = tempStack.top();
                std::cout << currentBook.title << " - " << currentBook.price << std::endl;
                tempStack.pop();
            }
        }
    }
};
#endif // CART_H