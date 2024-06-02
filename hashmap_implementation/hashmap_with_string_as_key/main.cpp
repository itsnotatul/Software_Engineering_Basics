#include "HashMap.h"
#include<iostream>

int main(){
    HashMap mp;
    mp.insert("atul",100);
    mp.insert("shubham",95);
    mp.getvalue("atul");
    mp.remove("shubham");
    cout<<mp.size()<<endl;

}