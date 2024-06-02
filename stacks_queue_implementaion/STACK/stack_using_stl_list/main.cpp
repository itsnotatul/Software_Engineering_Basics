#include<iostream>
#include "StackUsingList.h"

int main(){
    StackUsingList st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    std::cout<<st.top()<<std::endl;
    st.pop();
    st.pop();
    st.pop();
    std::cout<<st.top()<<std::endl;
    st.pop();
    std::cout<<st.top()<<std::endl;
    st.pop();
    std::cout<<st.top()<<std::endl;

    
}