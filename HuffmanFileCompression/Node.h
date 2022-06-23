#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    char ch;
    int frequency;
    Node *left = NULL;
    Node *right = NULL;
    Node *next;
    string binary;
    Node(char, int, Node *, Node *);
    Node();
};

#endif