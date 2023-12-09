#include <iostream>
#include <stack>
#include "Book.h"

// Assume 'Book' is defined with all the necessary fields, including 'description'.

std::stack<Book*> viewedBooks;

// Function to find a book by rank from your data structure (e.g., linked list)
// This is just a placeholder; you will need to implement this based on your actual data structure
Book* findBookByRank(Book* head, int rank) {
    while (head != nullptr) {
        if (head->rank == rank) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

// Function to view a book's details and push it onto the stack
void viewBook(Book* head, int rank) {
    Book* book = findBookByRank(head, rank);
    if (book != nullptr) {
        std::cout << "Rank: " << book->rank << std::endl;
        std::cout << "Title: " << book->title << std::endl;
        std::cout << "Price: $" << book->price << std::endl;
        std::cout << "Rating: " << book->rating << " / 5" << std::endl;
        std::cout << "Author: " << book->author << std::endl;
        std::cout << "Year of Publication: " << book->yearOfPublication << std::endl;
        std::cout << "Genre: " << book->genre << std::endl;
        std::cout << "URL: " << book->url << std::endl;
        std::cout << "Description: " << book->description << std::endl << std::endl;
        
        // Push the viewed book onto the stack
        viewedBooks.push(book);
    } else {
        std::cout << "Book with rank " << rank << " not found." << std::endl;
    }
}

// Optionally, a function to get the most recently viewed book without removing it from the stack
void showMostRecentlyViewedBook() {
    if (!viewedBooks.empty()) {
        Book* book = viewedBooks.top();
        std::cout << "Most recently viewed book:" << std::endl;
        std::cout << "Title: " << book->title << " (Rank: " << book->rank << ")" << std::endl;
    } else {
        std::cout << "No books have been viewed recently." << std::endl;
    }
}
