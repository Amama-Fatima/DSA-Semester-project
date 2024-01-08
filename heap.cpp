#include "bookheap.h"
#include <vector>
#include <stdexcept>         //exceptional handling import
#include <iostream>
using namespace std;

class BookHeap {
private:
    vector<Book> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].rating < heap[index].rating) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);

        if (leftChildIndex < heap.size() && heap[leftChildIndex].rating > heap[largest].rating) {
            largest = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex].rating > heap[largest].rating) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

public:
    void insert(const Book& book) {
        heap.push_back(book);
        heapifyUp(heap.size() - 1);
    }

    Book extractMax() {
        if (heap.size() == 0) {
            throw out_of_range("Heap is empty");
        }

        Book max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void printHeap() const {
        for (const auto& book : heap) {
            cout << "Book: " << book.title << ", Rating: " << book.rating << endl;
        }
    }
};
