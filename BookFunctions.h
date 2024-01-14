// BookFunctions.h
#ifndef BOOKFUNCTIONS_H
#define BOOKFUNCTIONS_H

#include "Book.h"
using namespace std;

void CreateGraph(Book* head);
void createAdjacentGraph(Book* head);
void primMST(int** graph, int srcId, int numVertices);
int* recommendBook();
#endif 

