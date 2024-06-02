#pragma once
#include<iostream>
#include<list>
using namespace std;

class StackUsingList{
list<int> _list;
public:
    StackUsingList();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int top();
};
