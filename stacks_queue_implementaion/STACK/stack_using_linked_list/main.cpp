#include<iostream>
#include "StackUsingLL.h"

int main(){
    stack_using_ll::StackUsingLL st;
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