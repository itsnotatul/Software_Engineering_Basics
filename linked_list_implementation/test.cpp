#include<iostream>
using namespace std;

int main(){
    int i=10;
    cout<<i<<" "<<&i<<endl;

    int *p=&i;
    cout<<p<<" "<<&p<<" "<<*p<<endl;

//    int* q=p; //obviously same as p

int **q=&p;

cout<<q<<" "<<*q<<" "<<**q<<endl;

ListNode* prev, *curr, *nxt;
        prev=NULL;
        curr=head;
        if(curr)
        nxt=curr->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(curr)
            nxt=curr->next;
        }
        return prev;


}