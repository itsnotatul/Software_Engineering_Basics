#ifndef _Node_
#define _Node_

#include<iostream>

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

#endif