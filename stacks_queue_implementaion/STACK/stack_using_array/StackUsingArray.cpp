#include "StackUsingArray.h"
#include<iostream>

using namespace stack_using_array ;

StackUsingArray::StackUsingArray(){
    data = new int[4];
    capacity =4;
    next_index = 0;
}


void StackUsingArray::push(int data){
    if(next_index == capacity){
        int* tmp_data = new int(2*capacity);
        int j = 0;
        for(int i=0;i<capacity;i++) tmp_data[j++] = this->data[i];
        delete [] this->data;
        this->data = tmp_data;
        capacity = 2*capacity;
    }
    this->data[next_index++] = data;
}


void StackUsingArray::pop(){
    if(empty()){
        std::cout<<"stack is empty"<<std::endl;
        return;
    }
    next_index--;
}


int StackUsingArray::top(){
    if(empty()){
        std::cout<<"stack is empty"<<std::endl;
        return INT_MIN;
    }
    return data[next_index-1];
}


int StackUsingArray::size() { return next_index;}

bool StackUsingArray::empty() {return next_index == 0;}