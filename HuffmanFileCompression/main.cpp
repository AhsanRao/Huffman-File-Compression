#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "Huffman.cpp"
#include "LinkList.cpp"
#include "Node.cpp"
#include "Compare.cpp"
using namespace std;

int main()
{
    LinkedList list;
    string data = "\0", file;
    Huffman huff;
Start:
    cout << "\n\tFile Compression System\n";
    cout << "\nEnter the file name: ";
    cin >> file;
    ifstream in(file);
    if (!in.is_open())
    {
        cout << "\nFile not found!" << endl;
        goto Start;
    }
    string line = "";
    while (!in.eof())
    {
        getline(in, line);
        data = data + line;
    }
    if (data == "\0")
    {
        cout << "\nFile is empty!\nTry Other File" << endl;
        goto Start;
    }
    string unique = huff.findUnique(data);
    int length = unique.length();
    for (int i = 0; i < length; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (unique[i] == unique[j])
            {
                break;
            }
        }
        if (i == j)
        {
            Node *node = new Node;
            node->ch = unique[i];
            node->frequency = huff.findFrequency(data, unique[i]);
            node->left = NULL;
            node->right = NULL;
            node->next = NULL;
            list.insertNode(node);
        }
    }
    cout << "\n\t Extracted Data From File\n";
    cout << data << endl;
    cout << "\n\t Unique Characters in File\n";
    cout << unique << endl;
    Node *top = huff.orderedBinary(list, list.length());
    cout << "\n\tHuffman Ordered Tree\n";
    list.displayTree();
    cout << "\n\tHuffman Encoded Data\n";
    cout << huff.encodeData(data, list) << endl;
     //Writing the Compressed Data in File
    fstream outt("OrderedCompression.txt",ios::out);
    outt<<huff.encodeData(data, list);
    string pass = huff.encodeData(data, list);
    cout << "\n\tHuffman Decoded Data\n";
    cout << huff.decodeData(pass, top) << endl;
    cout << "\nComprehension Ratio: " << huff.calculateCompression(data, list) << endl;

    LinkedList list2 = list;
    top = huff.unorderedBinary(list, list.length());
    cout << "\n\tHuffman UnOrdered Tree\n";
    list.displayTree();
    cout << "\n\tHuffman Encoded Data\n";
    cout << huff.encodeData(data, list) << endl;
    //Writing the Compressed Data in File
    fstream out("UnOrderedCompression.txt",ios::out);
    out<<huff.encodeData(data, list);
    pass = huff.encodeData(data, list);
    cout << "\n\tHuffman Decoded Data\n";
    cout << huff.decodeData(pass, top) << endl;
    cout << "\nComprehension Ratio: " << huff.calculateCompression(data, list2) << endl;
}