#include "QueueUsingLL.h"
#include<iostream>

using namespace queue_using_ll;

QueueUsingLL::QueueUsingLL(){
    head = nullptr;
    tail = nullptr;
    sz = 0;
}


void QueueUsingLL::push(int data){
    Node* new_node = new Node(data);
    if(head == nullptr) head = tail = new_node;
    else {
        tail->next = new_node;
        tail = tail->next;
    }
    
    sz++;
}


void QueueUsingLL::pop(){
    if(empty()){
        std::cout<<"queue is empty"<<std::endl;
        return;
    }
    auto tmp = head->next;
    delete head;
    head =tmp;
    sz--;
}


int QueueUsingLL::front(){
    if(empty()){
        std::cout<<"queue is empty"<<std::endl;
        return INT_MIN;
    }
    return head->data;
}


int QueueUsingLL::size() { return sz;}

bool QueueUsingLL::empty() {return sz == 0;}