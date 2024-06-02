#ifndef Queue_Using_Array
#define Queue_Using_Array

namespace queue_using_array{

    class QueueUsingArray{
        int first_idx;
        int next_idx;
        int* data;
        int sz;
        int capacity;

    public:
    QueueUsingArray();
    int size();
    bool empty();
    void push(int data);
    void pop();
    int front();


    };
}


#endif