// WaitingList.cpp
#include <iostream>
#include "WaitingList.h"

using namespace std;

// Define the queue for the waiting list
static queue<Book*> waitingList;

void addBookToWaitingList(Book* book) {
    if (book != nullptr) {
        waitingList.push(book);
        cout << "Book '" << book->title << "' added to the waiting list." << endl;
    } else {
        cout << "Invalid book pointer." << endl;
    }
}

void listWaitingListBooks() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    queue<Book*> tempQueue = waitingList; // Copy the queue for iteration
    cout << "Books in the waiting list:" << endl;
    while (!tempQueue.empty()) {
        Book* book = tempQueue.front();
        cout << "Rank: " << book->rank << ", Title: " << book->title << endl;
        tempQueue.pop();
    }
}

void removeFirstBookFromWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty. No book to remove." << endl;
        return;
    }

    Book* book = waitingList.front();
    waitingList.pop();
    cout << "Book '" << book->title << "' removed from the waiting list." << endl;

    // If the Book objects are dynamically allocated, consider deleting them here
    // delete book;
}


