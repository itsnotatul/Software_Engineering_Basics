#include "QueueUsingLL.h"
#include<iostream>

using namespace queue_using_ll;

QueueUsingLL::QueueUsingLL(){
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

QueueUsingLL::~QueueUsingLL()
{
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;  // Clear tail to avoid dangling pointer
}


void QueueUsingLL::push(int data){
    Node* new_node = new Node(data);
    if(head == nullptr) {head =new_node; tail = new_node;}
    else {
        tail->next = new_node;
        tail = tail->next;
    }
    
    sz++;
    std::cout << "Pushed: " << data << ", Size: " << sz << std::endl;
}


void QueueUsingLL::pop(){
    if(empty()){
        std::cout<<"queue is empty"<<std::endl;
        return;
    }
    auto tmp = head;
    head = head->next;
    delete tmp;
    if(head ==nullptr) tail = nullptr;
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