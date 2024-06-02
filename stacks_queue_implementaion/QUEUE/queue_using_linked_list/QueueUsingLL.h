#ifndef Queue_Using_LL
#define Queue_Using_LL
#include<iostream>
#include "Node.h"

namespace queue_using_ll{


class QueueUsingLL{
 
Node* head;
Node* tail;
int sz;
public:
    QueueUsingLL();
    ~QueueUsingLL();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int front();
};

}


#endif