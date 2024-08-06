#include<iostream>
#include<thread>
#include<future>
#include<chrono>

using namespace std;

void findOddSum(std::promise<int>& promiseObj, int st, int en){
    int oddSum =0;
    for(int i=st;i<=en;i++){
        if( (i&1)!=0) oddSum+=i;
    }
    promiseObj.set_value(oddSum);
}

int main(){

    int start = 0, end = 100;
    std::promise<int> oddSum;
    std::future<int> oddSumFuture = oddSum.get_future();

    std::thread t(findOddSum, std::ref(oddSum), start, end);
    // need to pass the promise object in the thread callable, which in turn will 
    // set the future object inside thread callable. 

/* note:
Passing by Reference: In the second code, the std::promise<int>& (a reference to a 
promise) is passed to the thread function. However, when you start the thread with 
std::thread t(findOddSum, oddSum, start, end);, the std::thread constructor copies its 
arguments by value. This means the std::promise<int> is copied, and the reference in 
findOddSum no longer refers to the original oddSum object but to the copied promise.
*/

    cout<< "Waiting for the Result"<<endl;
    std::this_thread::sleep_for(chrono::seconds(1));
    cout<<" Odd Sum between given start and end is : "<< oddSumFuture.get()<<endl;

    if(t.joinable()) t.join();
    return 0;
}
