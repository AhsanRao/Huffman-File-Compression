#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
class LinkedList
{
public:
    Node *head;
    LinkedList();
    int length();
    void setCode(char, string );
    void insertNode(Node *);
    string getBinary(char );
    void displayTree();
};
#endif