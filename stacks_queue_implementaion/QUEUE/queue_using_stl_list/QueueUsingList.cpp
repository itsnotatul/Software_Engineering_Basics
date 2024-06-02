#include "QueueUsingList.h"
#include<iostream>


QueueUsingList::QueueUsingList()
{
    _list.clear();
}

QueueUsingList::~QueueUsingList()
{
    
}

int QueueUsingList::size()
{
    return _list.size();
}

bool QueueUsingList::empty()
{
    return _list.size() == 0;
}

void QueueUsingList::push(int data)
{
    _list.push_back(data);
}

void QueueUsingList::pop()
{
    _list.pop_front();
}

int QueueUsingList::front()
{
    if(empty()) {cout<<"queue is empty" <<endl; return INT_MIN;}
    return _list.front();
}
