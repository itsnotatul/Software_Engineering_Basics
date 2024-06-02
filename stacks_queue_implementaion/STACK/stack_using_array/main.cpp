#include<iostream>
#include"StackUsingArray.h"

int main(){

    stack_using_array::StackUsingArray st2;
    st2.push(3);
    st2.push(4);
    st2.push(5);
    st2.push(6);
    st2.push(7);
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    st2.pop();
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    
}