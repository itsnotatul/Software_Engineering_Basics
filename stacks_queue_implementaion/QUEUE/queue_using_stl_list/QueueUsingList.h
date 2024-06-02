#pragma once
#include<iostream>
#include <list>
using namespace std;

class QueueUsingList{
list<int> _list; 
public:
    QueueUsingList();
    ~QueueUsingList();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int front();
};


