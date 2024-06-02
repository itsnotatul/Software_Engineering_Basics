#ifndef Stack_Using_LL
#define Stack_Using_LL
#include<iostream>
#include "Node.h"

namespace stack_using_ll{


class StackUsingLL{
 
Node* head;
int sz;
public:
    StackUsingLL();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int top();
};

}


#endif