#include<iostream>
using namespace std;

class Node{
public:
    int key;
    Node* next;
    Node(int _key):key(_key),next(nullptr){cout<<"Node created"<<endl;}
    ~Node(){cout<<"Node destryoed"<<endl;}
};

// reverse LL;
Node* reverse(Node* head)
{
    Node*curr = head;
    Node*next = nullptr;
    Node*prev = nullptr;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// middle point ( 2nd middle node)
Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// middle point(1st middle point)
Node* middle2(Node* head){
    Node* slow = head;
    Node* fast = head->next; //difference is here, used in palindrome list

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// find if palindrome or not
bool palindrome(Node* head){
    Node* mid = middle2(head);
    Node* reverseLL = reverse(mid->next);

    while(head && reverseLL){
        if(head->key != reverseLL->key) return false;
        head = head->next;
        reverseLL= reverseLL->next;
    }
    return true;
}

// detect cycle
bool cycle(Node* head){
    Node*slow = head;
    Node*fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

//if cycle present, return starting point of the cycle
Node* startingPoint(Node* head){
    Node*slow = head;
    Node* fast = head;

    while(fast && fast->next){
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast){ // cycle is present
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
       }
    }
    return nullptr; //cycle not present
}

// return intersection of two lists
Node *getIntersectionNode(Node *headA, Node *headB) {

    Node* d1= headA;
    Node* d2= headB;
    while(d1!=d2){
        d1=(d1==nullptr)? headB: d1->next; // if another list is just a part of main list
        d2=(d2==nullptr)? headA: d2->next;
    }
    return d1;
}


// merge two sorted lists
Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* dummyHead = new Node(0);
        Node* tail = dummyHead;

        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->key < l2->key){
                tail->next = l1;
                tail = tail->next;
                l1= l1->next;
            }
            else{
                tail->next = l2;
                tail= tail->next;
                l2=l2->next;
            }

        }
        if(l1) tail->next = l1;
        if(l2)tail->next = l2;

        return dummyHead->next;
    }

// remove nth node from the end
 Node* removeNthFromEnd(Node* head, int n) {
        Node* slow = head;
        Node* fast = head;

        for(int i=0;i<n;i++)fast=fast->next;
        if(fast == nullptr) { // if n==l ==> deleting first node of list
            Node* ret = head->next;
            delete head;
            return ret;
        }
        while(fast->next!=nullptr){ // important
            slow =slow->next;
            fast = fast->next;
        } 
        Node* del = slow->next;
        if(slow && slow->next) // for edge cases
            slow->next = slow->next->next;
        delete del;
        
        return head;
    }

int main(){
    return 0;
}