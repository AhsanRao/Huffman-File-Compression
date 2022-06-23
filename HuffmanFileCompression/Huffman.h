#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <string>
#include <queue>
#include "Node.h"
#include "LinkList.h"
#include "Compare.h"
using namespace std;
class Huffman
{
public:
    string findUnique(string);
    int findFrequency(string, char);
    void createBinary(Node *, string, LinkedList &);
    string encodeData(string, LinkedList &);
    string decodeData(string, Node *);
    Node *orderedBinary(LinkedList &, int);
    Node *unorderedBinary(LinkedList &, int);
    double calculateCompression(string, LinkedList &);
};
#endif