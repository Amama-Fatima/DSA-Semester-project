// WaitingList.h
#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <queue>
#include "Book.h" // Include the Book class header

void addBookToWaitingList(Book* book);
void listWaitingListBooks();
void removeFirstBookFromWaitingList();

#endif // WAITINGLIST_H
