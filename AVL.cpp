#include "AVL.h"

int AVLTree::getHeight(AVLNode *node)
{
        if (node == nullptr)
            return 0;
        return node->height;
}

int AVLTree::getBalance(AVLNode *node)
{
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
}

AVLTree::AVLNode *AVLTree::rotateRight(AVLNode *y)
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

AVLTree::AVLNode *AVLTree::rotateLeft(AVLNode *x)
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

AVLTree::AVLNode *AVLTree::insertById(AVLNode *node, Book book)
{
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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

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




AVLTree::AVLNode *AVLTree::insertByLikedPercent(AVLNode *node, Book book)
{
           //Perform standard BST insertion
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

AVLTree::AVLNode *AVLTree::insertByPrice(AVLNode *node, Book book)
{
        if (node == nullptr)
            return new AVLNode(book);

        if (book.price < node->data.price)
            node->left = insertByPrice(node->left, book);
        else if (book.price > node->data.price)
            node->right = insertByPrice(node->right, book);
        else
        {   
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

AVLTree::AVLNode *AVLTree::insertByPages(AVLNode *node, Book book)
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

void AVLTree::searchByLikedPercentRange(AVLNode *node, int minLikedPercent, int maxLikedPercent, std::vector<Book *> &result)
{
            if (node == nullptr)
            return;

        if (node->data.likedPercent >= minLikedPercent && node->data.likedPercent <= maxLikedPercent)
        {
            result.push_back(&(node->data));
            AVLNode *temp = node->another;
            while (temp != nullptr)
            {
                result.push_back(&(temp->data));
                temp = temp->another;
            }
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

void AVLTree::searchByPriceRange(AVLNode *node, double minPrice, double maxPrice, std::vector<Book *> &result)
{
            if (node == nullptr)
            return;

        if (node->data.price >= minPrice && node->data.price <= maxPrice)
        {
            result.push_back(&(node->data));
            AVLNode *temp = node->another;
            while (temp != nullptr)
            {
                result.push_back(&(temp->data));
                temp = temp->another;
            }
        }

        if (node->data.price > minPrice)
        {
            searchByPriceRange(node->left, minPrice, maxPrice, result);
        }

        if (node->data.price < maxPrice)
        {
            searchByPriceRange(node->right, minPrice, maxPrice, result);
        }
}

void AVLTree::searchByPagesRange(AVLNode *node, double minPages, double maxPages, std::vector<Book *> &result)
{
        if (node == NULL)
            return;

        if (node->data.pages >= minPages && node->data.pages <= maxPages)
        {
            result.push_back(&(node->data));
            AVLNode *temp = node->another;
            while (temp != nullptr)
            {
                result.push_back(&(temp->data));
                temp = temp->another;
            }
            
        }

        if (node->data.pages > minPages)
        {
            searchByPagesRange(node->left, minPages, maxPages, result);
        }

        if (node->data.pages < maxPages)
        {
            searchByPagesRange(node->right, minPages, maxPages, result);
        }
}

Book *AVLTree::searchById(AVLNode *node, int id)
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

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::AVLNode* AVLTree::getRoot()
{
    return root;
}

void AVLTree::insertId(Book book)
{
    root = insertById(root, book);
}

void AVLTree::insertLikedPercent(Book book)
{
    root = insertByLikedPercent(root, book);
}

void AVLTree::insertPrice(Book book)
{
    root = insertByPrice(root, book);
}

void AVLTree::insertPages(Book book)
{
    root = insertByPages(root, book);
}

std::vector<Book *> AVLTree::searchLikedPercentRange(int minLikedPercent, int maxLikedPercent)
{
    std::vector<Book *> result;
    searchByLikedPercentRange(root, minLikedPercent, maxLikedPercent, result);
    return result;
}

std::vector<Book *> AVLTree::searchPriceRange(double minPrice, double maxPrice)
{
    std::vector<Book *> result;
    searchByPriceRange(root, minPrice, maxPrice, result);
    return result;
}

std::vector<Book *> AVLTree::searchPagesRange(double minPages, double maxPages)
{
    std::vector<Book *> result;
    searchByPagesRange(root, minPages, maxPages, result);
    return result;
}

Book *AVLTree::searchId(int id)
{   
    return searchById(root, id);
}
