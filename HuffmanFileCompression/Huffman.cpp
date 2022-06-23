#include "Huffman.h"
string Huffman::findUnique(string st)
{
    string str;
    int length = st.length();
    for (int i = 0; i < length; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (st[i] == st[j])
            {
                break;
            }
        }
        if (i == j)
            str = str + st[i];
    }
    return str;
}
int Huffman::findFrequency(string str, char ch)
{

    int i = 0, count = 0;

    while (str[i] != '\0')
    {

        if (str[i] == ch)
        {
            count++;
        }
        i++;
    }

    return count;
}

void Huffman::createBinary(Node *node, string str, LinkedList &l)
{
    if (node != nullptr)
    {
        if (node->ch != '*')
            l.setCode(node->ch, str);

        createBinary(node->left, str + '0', l);
        createBinary(node->right, str + '1', l);
    }
}
string Huffman::encodeData(string str, LinkedList &l)
{
    string str2 = "";
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        string stt = l.getBinary(str[i]);
        str2 += stt;
    }
    return str2;
}
string Huffman::decodeData(string s, Node *node)
{
    string res = "";
    Node *temp = node;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;
        if (temp->left == NULL and temp->right == NULL)
        {
            res += temp->ch;
            temp = node;
        }
    }

    return res;
}
Node *Huffman::orderedBinary(LinkedList &l, int length)
{
    Node *left, *right, *top;
    priority_queue<Node *, vector<Node *>, Compare> que;

    Node *ptr = l.head;
    while (ptr)
    {
        que.push(ptr);
        ptr = ptr->next;
    }

    for (int i = 1; i < length; i++)
    {
        left = que.top();
        que.pop();
        right = que.top();
        que.pop();
        top = new Node('*', left->frequency + right->frequency, left, right);
        que.push(top);
    }
    createBinary(que.top(), "", l);
    return que.top();
}
Node *Huffman::unorderedBinary(LinkedList &l, int length)
{
    Node *left, *right, *top;
    queue<Node *> que;

    Node *ptr = l.head;
    while (ptr)
    {
        que.push(ptr);
        ptr = ptr->next;
    }

    for (int i = 1; i < length; i++)
    {
        left = que.front();
        que.pop();

        right = que.front();
        que.pop();

        top = new Node('*', left->frequency + right->frequency, left, right);
        que.push(top);
    }

    createBinary(que.front(), "", l);
    return que.front();
}
double Huffman::calculateCompression(string str, LinkedList &l)
{
    double compression = 0;
    Node *ptr = l.head;
    while (ptr)
    {
        compression += ptr->frequency * ptr->binary.length();
        ptr = ptr->next;
    }
    compression = compression / str.length();
    return 8 / compression;
}