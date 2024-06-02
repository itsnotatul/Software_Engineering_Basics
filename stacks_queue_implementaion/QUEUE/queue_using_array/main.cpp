#include<iostream>
#include "QueueUsingArray.h"

int main(){
   

    queue_using_array::QueueUsingArray que;
    que.push(9);
    que.push(10);
    que.push(11);
    que.push(12);
    que.push(13);
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