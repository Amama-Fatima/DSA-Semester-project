#ifndef HEAP_H
#define HEAP_H

#include "Book.h"
#include <vector>

class BookHeap {
public:
    
    BookHeap() = default;
    void insert(const Book& book);
    Book extractMax();
    bool isEmpty() const;
    void printHeap() const;

private:
    
    std::vector<Book> heap;

    
    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
};

#endif 
