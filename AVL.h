#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include "Book.h"
#include <vector>

class AVLTree
{
private:
    struct AVLNode
    {
        Book data;
        AVLNode *left;
        AVLNode *right;
        AVLNode *another;  // Pointer to the next node with the same attribute value
        int height;

        AVLNode(Book book) : data(book), left(NULL), right(NULL), another(NULL), height(1) {}
    };

    AVLNode *root;

    int getHeight(AVLNode *node);

    int getBalance(AVLNode *node);

    AVLNode *rotateRight(AVLNode *y);

    AVLNode *rotateLeft(AVLNode *x);

    AVLNode *insertById(AVLNode *node, Book book);

    AVLNode *insertByLikedPercent(AVLNode *node, Book book);

    AVLNode *insertByPrice(AVLNode *node, Book book);

    AVLNode *insertByPages(AVLNode *node, Book book);

    void searchByLikedPercentRange(AVLNode *node, int minLikedPercent, int maxLikedPercent, std::vector<Book *> &result);

    void searchByPriceRange(AVLNode *node, double minPrice, double maxPrice, std::vector<Book *> &result);

    void searchByPagesRange(AVLNode *node, double minPages, double maxPages, std::vector<Book *> &result);

    // Helper function for searching by book ID
    Book *searchById(AVLNode *node, int id);

public:
    AVLTree();

    AVLNode* getRoot();

    void insertId(Book book);

    void insertLikedPercent(Book book);

    void insertPrice(Book book);

    void insertPages(Book book);

    // Function to search by liked percent range
    std::vector<Book *> searchLikedPercentRange(int minLikedPercent, int maxLikedPercent);

    // Function to search by price range
    std::vector<Book *> searchPriceRange(double minPrice, double maxPrice);

    // Function to search by pages range
    std::vector<Book *> searchPagesRange(double minPages, double maxPages);

    // Function to search by book ID
    Book *searchId(int id);

};

#endif 