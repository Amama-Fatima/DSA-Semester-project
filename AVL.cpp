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
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

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
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

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

     // Recursive function to search in AVL tree
    Book *searchInAVLTree(AVLNode *node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (value < node->data.likedPercent)
            return searchInAVLTree(node->left, value);
        else if (value > node->data.likedPercent)
            return searchInAVLTree(node->right, value);
        // else
        // {
        //     // Value found in AVL tree, now search in linked list
        //     AVLNode *temp = node;
        //     while (temp != nullptr)
        //     {
        //         if (temp->data.likedPercent == value)
        //             return &(temp->data);
        //         temp = temp->another;
        //     }
        // }

        return nullptr; // Not found
    }

public:
    AVLTree() : root(nullptr) {}

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

    // Function to search by liked percent
    Book *searchByLikedPercent(int likedPercent)
    {
        return searchInAVLTree(root, likedPercent);
    }

    Book *searchByPrice(double price)
    {
        return searchInAVLTree(root, price);
    }

    Book *searchByPages(double pages)
    {
        return searchInAVLTree(root, pages);
    }

    // Add other member functions as needed
};

int main()
{
    AVLTree avlTree;
    // Usage example:
    avlTree.insertLikedPercent(Book(/* some book data */));
    // Perform other operations on the AVL tree
    return 0;
}