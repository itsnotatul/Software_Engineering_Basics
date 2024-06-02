#include<iostream>
#include"StackUsingArray.h"
#include "StackUsingLL.h"
#include "QueueUsingArray.h"

int main(){
    stack_using_ll::StackUsingLL st;
    st.push(3);
    st.push(3);
    st.push(3);
    st.push(3);
    st.push(3);
    std::cout<<st.top()<<std::endl;
    st.pop();
    st.pop();
    st.pop();
    std::cout<<st.top()<<std::endl;
    st.pop();
    std::cout<<st.top()<<std::endl;
    st.pop();
    std::cout<<st.top()<<std::endl;

    stack_using_array::StackUsingArray st2;
    st2.push(3);
    st2.push(3);
    st2.push(3);
    st2.push(3);
    st2.push(3);
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    st2.pop();
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    st2.pop();
    std::cout<<st2.top()<<std::endl;
    

    queue_using_array::QueueUsingArray que;
    que.push(3);
    que.push(3);
    que.push(3);
    que.push(3);
    que.push(3);
    std::cout<<que.front()<<std::endl;
    que.pop();
    que.pop();
    que.pop();
    std::cout<<que.front()<<std::endl;
    que.pop();
    std::cout<<que.front()<<std::endl;
    que.pop();
    std::cout<<que.front()<<std::endl;

}