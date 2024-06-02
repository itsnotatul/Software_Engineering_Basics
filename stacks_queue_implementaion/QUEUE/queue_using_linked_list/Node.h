#ifndef _Node_
#define _Node_

#include<iostream>

class Node{
    public:
    int data;
    Node* next;

    Node(int _data): data(_data), next(nullptr){std::cout<<"NODE CREATED"<<std::endl;}
    ~Node(){ std::cout<<"NODE DESTROYED"<<std::endl;}
};

#endif