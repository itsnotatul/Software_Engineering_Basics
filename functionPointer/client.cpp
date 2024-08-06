#include "Library.h"
#include <iostream>
#include<chrono>
#include<thread>

using namespace std;

void ClientCallback(string response, void* user_data){
    cout<<"client callback"<<endl;
    cout<<response<<endl;
}

int main(){
    init(ClientCallback);
    ServerFun("hello server, I am a client request");
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout<<"fuckesh"<<endl;
    return 0;
}

