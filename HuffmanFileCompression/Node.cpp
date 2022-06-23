#include "Node.h"
Node::Node()
{
}
Node::Node(char c, int f, Node *left, Node *right)
{
    ch = c;
    frequency = f;
    this->left = left;
    this->right = right;
    next = NULL;
    binary = "";
}