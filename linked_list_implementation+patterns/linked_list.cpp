#include<iostream>
using namespace std;

class Node{
public:
    int key;
    Node*next;
    Node(int _key): key(_key), next(nullptr){cout<<"NODE CREATED"<<endl;}
    ~Node(){cout<<"NODE DESTROYED"<<endl;}    
};


int main(){
   Node* head = nullptr;
   Node* tail = nullptr;

   cout<<"Enter the node value to be inserted in linked list"<<endl;
   int data;
   cin>> data;
   while(data!=-1){
    Node* new_node = new Node(data);
    if(head == nullptr) head = tail = new_node;
    else {
        tail->next = new_node;
        tail = tail->next;
    }
    cout<<"Enter the node value to be inserted in linked list"<<endl;
    cin>>data;
   }

   //print
   auto tmp = head;
   while(tmp){
    cout<<tmp->key<<" ";
    tmp = tmp->next;
   }
   cout<<endl;

   //free memory
   while(head!=nullptr){
        tmp = head;
        head = head->next;

        tmp->next = nullptr;
        delete tmp;
   }
}