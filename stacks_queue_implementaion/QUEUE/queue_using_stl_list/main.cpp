#include<iostream>
#include "QueueUsingList.h"

int main(){
   
    QueueUsingList que2;
    que2.push(9);
    que2.push(10);
    que2.push(11);
    que2.push(12);
    que2.push(13);
    std::cout<<que2.front()<<std::endl;
    que2.pop();
    que2.pop();
    que2.pop();
    std::cout<<que2.front()<<std::endl;
    que2.pop();
    std::cout<<que2.front()<<std::endl;
    que2.pop();
    std::cout<<que2.front()<<std::endl;

}