#include<bits/stdc++.h>


class PriorityQueue {
    // Complete this class
    vector<int>data;
    public:
   bool isEmpty(){
       return data.size()==0;
   }
   int getSize(){
       return data.size();
   } 
   int getMax(){
       if(isEmpty()){ // isEmpty() called on current object of priorityQueue class 
           return INT_MIN;
       }
       return data[0];
   } 
    
   void insert(int element){
       data.push_back(element);
       
       //up-heapify
       int childIndex=data.size()-1;
       while(childIndex > 0){
           int parentIndex=(childIndex-1)/2;
               if(data[parentIndex] < data[childIndex]){
                   swap(data[parentIndex],data[childIndex]);
               }
               else{ //inserted at correct position
                   break;
               }
           childIndex=parentIndex;
       }
   }
   
    int removeMax(){
         if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        
        int ans=data[0];
        data[0]=data[data.size()-1];
        data[data.size()-1]=ans;
        data.pop_back();
        
        //DOWN-HEAPIFY  
        int parentIndex=0;
        int leftChildIndex  = 2*(parentIndex)+1;
        int rightChildIndex = 2*(parentIndex)+2;
        
        while(leftChildIndex<data.size()){
            int maxIndex = parentIndex;
            if(data[maxIndex]<data[leftChildIndex]){
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<data.size() && data[maxIndex]<data[rightChildIndex]){
                maxIndex=rightChildIndex;
            }
            
            if(maxIndex==parentIndex){
                break;
            }
            else{
                swap(data[maxIndex],data[parentIndex]);
            }
            parentIndex=maxIndex;
            leftChildIndex  = 2*(parentIndex)+1;
            rightChildIndex = 2*(parentIndex)+2;
        }
        return ans;
    }
         
         
};
