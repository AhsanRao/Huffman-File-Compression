#include "LinkList.h"
LinkedList::LinkedList()
{
    head = NULL;
}

int LinkedList::length()
{

    Node *ptr = head;
    int i = 0;

    while (ptr)
    {
        i++;
        ptr = ptr->next;
    }
    return i;
}

void LinkedList::setCode(char ch, string binary)
{
    Node *ptr = head;

    while (ptr)
    {
        if (ptr->ch == ch)
        {
            ptr->binary = binary;
        }
        ptr = ptr->next;
    }
}

void LinkedList::insertNode(Node *node)
{
    Node *temp = new Node;
    temp->ch = node->ch;
    temp->frequency = node->frequency;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
string LinkedList::getBinary(char ch)
{
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->ch == ch)
        {
            return ptr->binary;
        }
        ptr = ptr->next;
    }
    return ptr->binary;
}
void LinkedList::displayTree()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "\n\tCharacter: " << temp->ch << "\tFrequency: " << temp->frequency << "\tBinary: " << temp->binary;
        temp = temp->next;
    }
    cout << endl;
}