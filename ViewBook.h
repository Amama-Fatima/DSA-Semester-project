#ifndef VIEWBOOK_H
#define VIEWBOOK_H

#include "Book.h" // Include the Book class header

// Function declarations
Book* findBookByRank(Book* head, int rank);
void viewBook(Book* head, int rank);
void showMostRecentlyViewedBook();

#endif // VIEWBOOK_H
