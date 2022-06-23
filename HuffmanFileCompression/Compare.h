#ifndef COMPARE_H
#define COMPARE_H
#include <iostream>
#include <string>
#include "Node.h"
class Compare
{
public:
    bool operator()(Node *, Node *);
};
#endif