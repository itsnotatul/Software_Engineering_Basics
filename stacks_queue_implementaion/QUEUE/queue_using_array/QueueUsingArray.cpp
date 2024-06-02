#include "QueueUsingArray.h"
#include<iostream>

using namespace queue_using_array;

QueueUsingArray:: QueueUsingArray(){
    data = new int[4];
    first_idx = -1;
    next_idx = 0;
    sz = 0;
    capacity =4;
}

void QueueUsingArray::push(int data){
    if(sz == capacity){
        int* tmp_data = new int[2*capacity];
        int j =0;
        for(int i=first_idx;i<capacity;i++) tmp_data[j++] = this->data[i];
        for(int i=0;i<first_idx;i++) tmp_data[j++] = this->data[i];
        
        delete [] this->data;
        this->data = tmp_data;
        next_idx = capacity;
        capacity*=2;
        first_idx = 0;
    }
    sz++;
    this->data[next_idx] = data;
    next_idx = (next_idx +1) % capacity;
    if(first_idx == -1) first_idx = 0;
}


void QueueUsingArray::pop(){
    if(empty()){
        std::cout<<"queue is empty"<<std::endl;
        return;
    }
    sz--;
    first_idx = (first_idx+1)% capacity;
    if(first_idx == 0) first_idx = -1;
}


int QueueUsingArray::front(){
    if(empty()){
        std::cout<<"queue is empty"<<std::endl;
        return INT_MIN;
    }
    return data[first_idx];
}


int QueueUsingArray::size() { return sz;}

bool QueueUsingArray::empty() {return sz == 0;}