#ifndef Stack_Using_Array
#define Stack_Using_Array

namespace stack_using_array{

class StackUsingArray{
 int* data;
 int next_index;
 int capacity;

public:
    StackUsingArray();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int top();
};


}



#endif