#include <iostream>
#include "Book.h"
using namespace std;

int height(Book *book){
    if(book==NULL){
        return 0;
    }
    return book->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

Book* rightRotate(Book *y){
    Book *x = y->left;
    Book* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

Book* leftRotate(Book* x){
    Book* y = x->right;
    Book* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(Book* book){
    if(book==NULL){
        return 0;
    }
    return height(book->left) - height(book->right);
}

Book* adjust(Book* book){
    
    int balance = getBalance(book);

    if(balance > 1 && book->likedPercent < book->left->likedPercent){
        return rightRotate(book);
    }

    if(balance < -1 && book->likedPercent > book->right->likedPercent){
        return leftRotate(book);
    }

    if(balance > 1 && book->likedPercent > book->left->likedPercent){
        book->left = leftRotate(book->left);
        return rightRotate(book);
    }

    if(balance < -1 && book->likedPercent < book->right->likedPercent){
        book->right = rightRotate(book->right);
        return leftRotate(book);
    }

    return book;
}