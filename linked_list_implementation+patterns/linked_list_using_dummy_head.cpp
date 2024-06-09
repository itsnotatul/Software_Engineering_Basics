#include<iostream>
using namespace std;

class Node{
public:
    int key;
    Node* next;
    Node(int _key):key(_key),next(nullptr){cout<<"Node created"<<endl;}
    ~Node(){cout<<"Node destryoed"<<endl;}
};

int main(){
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    int n;
    cout<<"Enter the number of nodes to be inserted"<<endl;
    cin>>n;

    int _key;
    while(n!=0){
        cin>>_key;
        Node* new_node = new Node(_key);
        tail->next = new_node;
        tail = tail->next;
        n--;
    }
    Node* head = dummy->next;

    //print
    while(head){
        cout<<head->key<<"->";
        head=head->next;
    }
    cout<<"nullptr"<<endl;
    //delete nodes
    head = dummy->next;
    while(head){
        Node* tmp = head;
        head=head->next;
        tmp->next = nullptr;
        delete tmp;
    }
    dummy->next = nullptr;
    delete dummy;
}