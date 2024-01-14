#include "bookheap.h"
#include <vector>
#include <stdexcept>         //exceptional handling import
#include <iostream>
#include <vector>

using namespace std;

class CustomHeap {
public:
    vector<pair<int, pair<int, int>>> items;  // Change to vector<pair<int, pair<int, int>>>

    CustomHeap() {}

    // Add this function to the CustomHeap class
    bool isEmpty() {
        return items.empty();
    }

    int getLeftChildIndex(int parentIndex) {
        return (parentIndex * 2) + 1;
    }

    int getRightChildIndex(int parentIndex) {
        return (parentIndex * 2) + 2;
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    bool hasLeftChild(int index) {
        return getLeftChildIndex(index) < items.size();
    }

    bool hasRightChild(int index) {
        return getRightChildIndex(index) < items.size();
    }

    bool hasParent(int index) {
        return getParentIndex(index) >= 0;
    }

    pair<int, pair<int, int>> leftChild(int index) {
        return items[getLeftChildIndex(index)];
    }

    pair<int, pair<int, int>> rightChild(int index) {
        return items[getRightChildIndex(index)];
    }

    pair<int, pair<int, int>> parent(int index) {
        return items[getParentIndex(index)];
    }

    void swap(int indexOne, int indexTwo) {
        pair<int, pair<int, int>> temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    pair<int, pair<int, int>> poll() {
        pair<int, pair<int, int>> item = items[0];
        items[0] = items.back();
        items.pop_back();
        heapifyDown();
        return item;
    }

    void add(pair<int, pair<int, int>> item) {
        items.push_back(item);
        heapifyUp();
    }

    void heapifyDown() {
        int index = 0;

        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);

            if (hasRightChild(index) && compare(leftChild(index), rightChild(index)) > 0) {
                smallerChildIndex = getRightChildIndex(index);
            }

            if (compare(items[index], items[smallerChildIndex]) < 0) {
                break;
            } else {
                swap(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }
    }

    void heapifyUp() {
        int index = items.size() - 1;

        while (hasParent(index) && compare(items[index], parent(index)) < 0) {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }   
    }

private:
    // Custom comparison function based on distance, weight, and vertex number
    int compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.first != b.first) {
            return a.first - b.first;  // Compare based on distance
        } else if (a.second.second != b.second.second) {
            return b.second.second - a.second.second;  // Compare based on weight
        } else if(a.second.first != b.second.first) {
            return a.second.first - b.second.first;  // Compare based on vertex number
        }
    }
};