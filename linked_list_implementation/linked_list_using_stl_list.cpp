#include<iostream>
#include<list>

using namespace std;

int main(){

// list is internally implemented as doubly linked list
    list<int> _list;
    
    cout<<"Enter the node value to be inserted in linked list"<<endl;
    int data;
    cin>> data;
    while(data!=-1){
        _list.push_back(data);
        cout<<"Enter the node value to be inserted in linked list"<<endl;
        cin>>data;
    }

    //print
    for(auto it = _list.begin();it!=_list.end();it++){
        cout<<*it<<"->";
    }
    cout<<endl;

//delete any key;
cout<<"enter the key, you want to delete from the linked list"<<endl;
cin>>data;
for(auto it = _list.begin();it!=_list.end();it++){
        if(*it == data){
            _list.erase(it);
            break; //important step, otherwise segmenatation fault
        }
}

 //print after delete
    for(auto it = _list.begin();it!=_list.end();it++){
        cout<<*it<<"->";
    }
    cout<<endl;

}
