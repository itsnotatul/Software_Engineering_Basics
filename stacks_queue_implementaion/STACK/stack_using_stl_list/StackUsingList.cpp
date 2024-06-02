#include "StackUsingList.h"
#include<iostream>

StackUsingList::StackUsingList()
{
    _list.clear();
}

int StackUsingList::size()
{
    return _list.size();
}

bool StackUsingList::empty()
{
    return _list.size() == 0;
}

void StackUsingList::push(int data)
{
    _list.push_front(data);
}

void StackUsingList::pop()
{
    _list.pop_front();
}

int StackUsingList::top()
{
    if(empty()) {cout<<"stack is empty"<<endl;return INT_MIN;}
    return _list.front();
}
