#include "StackUsingLL.h"
#include<iostream>

using namespace stack_using_ll;

StackUsingLL::StackUsingLL(){
    head = nullptr;
    sz = 0;
}


void StackUsingLL::push(int data){
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
    sz++;
}


void StackUsingLL::pop(){
    if(empty()){
        std::cout<<"stack is empty"<<std::endl;
        return;
    }
    auto tmp = head->next;
    delete head;
    head =tmp;
    sz--;
}


int StackUsingLL::top(){
    if(empty()){
        std::cout<<"stack is empty"<<std::endl;
        return INT_MIN;
    }
    return head->data;
}


int StackUsingLL::size() { return sz;}

bool StackUsingLL::empty() {return sz == 0;}