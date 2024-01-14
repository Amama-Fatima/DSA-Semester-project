#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include "Book.h"
using namespace std;

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

        AVLNode(Book book) : data(book), left(nullptr), right(nullptr), height(1) {}
    };

    AVLNode *root;

    int getHeight(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *rotateRight(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode *rotateLeft(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

         AVLNode *insertById(AVLNode *node, Book book)
    {
        // Perform standard BST insertion
        if (node == nullptr)
            return new AVLNode(book);

        if (book.id < node->data.id)
            node->left = insertById(node->left, book);
        else if (book.id > node->data.id)
            node->right = insertById(node->right, book);
        else
        {
            // If the attribute value is the same, insert into the linked list
            AVLNode *temp = node;
            while (temp->another != nullptr)
            {
                temp = temp->another;
            }
            temp->another = new AVLNode(book);
            return node;
        }

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // Perform rotations if needed
        if (balance > 1 && book.id < node->left->data.id)
            return rotateRight(node);

        if (balance < -1 && book.id > node->right->data.id)
            return rotateLeft(node);

        if (balance > 1 && book.id > node->left->data.id)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && book.id < node->right->data.id)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }


    AVLNode *insertByLikedPercent(AVLNode *node, Book book)
    {
        // Perform standard BST insertion
        if (node == nullptr)
            return new AVLNode(book);

        if (book.likedPercent < node->data.likedPercent)
            node->left = insertByLikedPercent(node->left, book);
        else if (book.likedPercent > node->data.likedPercent)
            node->right = insertByLikedPercent(node->right, book);
        else
        {
            // If the attribute value is the same, insert into the linked list
            AVLNode *temp = node;
            while (temp->another != nullptr)
            {
                temp = temp->another;
            }
            temp->another = new AVLNode(book);
            // Do not update height when inserting into the linked list
            return node;
        }

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // Perform rotations if needed
        if (balance > 1 && book.likedPercent < node->left->data.likedPercent)
            return rotateRight(node);

        if (balance < -1 && book.likedPercent > node->right->data.likedPercent)
            return rotateLeft(node);

        if (balance > 1 && book.likedPercent > node->left->data.likedPercent)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && book.likedPercent < node->right->data.likedPercent)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

        AVLNode *insertByPrice(AVLNode *node, Book book)
    {
        // Perform standard BST insertion
        if (node == nullptr)
            return new AVLNode(book);

        if (book.price < node->data.price)
            node->left = insertByPrice(node->left, book);
        else if (book.price > node->data.price)
            node->right = insertByPrice(node->right, book);
        else
        {
            // If the attribute value is the same, insert into the linked list
            AVLNode *temp = node;
            while (temp->another != nullptr)
            {
                temp = temp->another;
            }
            temp->another = new AVLNode(book);
            return node;
        }

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // Perform rotations if needed
        if (balance > 1 && book.price < node->left->data.price)
            return rotateRight(node);

        if (balance < -1 && book.price > node->right->data.price)
            return rotateLeft(node);

        if (balance > 1 && book.price > node->left->data.price)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && book.price < node->right->data.price)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

        AVLNode *insertByPages(AVLNode *node, Book book)
    {
        // Perform standard BST insertion
        if (node == nullptr)
            return new AVLNode(book);

        if (book.pages < node->data.pages)
            node->left = insertByPages(node->left, book);
        else if (book.pages > node->data.pages)
            node->right = insertByPages(node->right, book);
        else
        {
            // If the attribute value is the same, insert into the linked list
            AVLNode *temp = node;
            while (temp->another != nullptr)
            {
                temp = temp->another;
            }
            temp->another = new AVLNode(book);
            return node;
        }

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor
        int balance = getBalance(node);

        // Perform rotations if needed
        if (balance > 1 && book.pages < node->left->data.pages)
            return rotateRight(node);

        if (balance < -1 && book.pages > node->right->data.pages)
            return rotateLeft(node);

        if (balance > 1 && book.pages > node->left->data.pages)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && book.pages < node->right->data.pages)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void searchByLikedPercentRange(AVLNode *node, int minLikedPercent, int maxLikedPercent, vector<Book *> &result)
    {
        if (node == nullptr)
            return;

        if (node->data.likedPercent >= minLikedPercent && node->data.likedPercent <= maxLikedPercent)
        {
            result.push_back(&(node->data));
        }

        if (node->data.likedPercent > minLikedPercent)
        {
            searchByLikedPercentRange(node->left, minLikedPercent, maxLikedPercent, result);
        }

        if (node->data.likedPercent < maxLikedPercent)
        {
            searchByLikedPercentRange(node->right, minLikedPercent, maxLikedPercent, result);
        }
    }

    void searchByPriceRange(AVLNode *node, double minPrice, double maxPrice, vector<Book *> &result)
    {
        if (node == nullptr)
            return;

        if (node->data.price >= minPrice && node->data.price <= maxPrice)
        {
            result.push_back(&(node->data));
        }

        if (node->data.price > minPrice)
        {
            searchByLikedPercentRange(node->left, minPrice, maxPrice, result);
        }

        if (node->data.price < maxPrice)
        {
            searchByLikedPercentRange(node->right, minPrice, maxPrice, result);
        }
    }

    void searchByPagesRange(AVLNode *node, double minPages, double maxPages, vector<Book *> &result)
    {
        if (node == nullptr)
            return;

        if (node->data.pages >= minPages && node->data.pages <= maxPages)
        {
            result.push_back(&(node->data));
        }

        if (node->data.pages > minPages)
        {
            searchByLikedPercentRange(node->left, minPages, maxPages, result);
        }

        if (node->data.pages < maxPages)
        {
            searchByLikedPercentRange(node->right, minPages, maxPages, result);
        }
    }

    Book *searchById(AVLNode *node, int id)
    {
        if (node == nullptr || node->data.id == id)
        {
            return (node != nullptr && node->data.id == id) ? &(node->data) : nullptr;
        }

        if (id < node->data.id)
        {
            return searchById(node->left, id);
        }
        else
        {
            return searchById(node->right, id);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    AVLNode* getRoot()
    {
        return root;
    }

    void insertId(Book book)
    {
        root = insertById(root, book);
    }

    void insertLikedPercent(Book book)
    {
        root = insertByLikedPercent(root, book);
    }

    void insertPrice(Book book)
    {
        root = insertByPrice(root, book);
    }

    void insertPages(Book book)
    {
        root = insertByPages(root, book);
    }

    vector<Book *> searchLikedPercentRange(int minLikedPercent, int maxLikedPercent)
    {
        vector<Book *> result;
        searchByLikedPercentRange(root, minLikedPercent, maxLikedPercent, result);
        return result;
    }

    vector<Book *> searchPriceRange(double minPrice, double maxPrice)
    {
        vector<Book *> result;
        searchByPriceRange(root, minPrice, maxPrice, result);
        return result;
    }

    vector<Book *> searchPagesRange(double minPages, double maxPages)
    {
        vector<Book *> result;
        searchByPagesRange(root, minPages, maxPages, result);
        return result;
    }

    Book *searchId(int id)
    {
        return searchById(root, id);
    }

};

#endif 