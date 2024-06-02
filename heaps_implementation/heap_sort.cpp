#include<iostream>

using namespace std;
void inplaceHeapSort(int arr[], int n){

  ///first convert unsorted array into HEAP with taking first element already in the  heap => first insert all elements of arr from index 1 into heap(MAX/MIN)
  for(int i=1;i<n;i++){ 
     int childIndex=i;
       while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(arr[childIndex] < arr[parentIndex]) {
                int temp = arr[childIndex];
                arr[childIndex]=arr[parentIndex];
                arr[parentIndex]=temp;
              
            }
            else {// meaing inserted at correct  position
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    /// now perform down heapify until size of unsorted array is 1(as we decrease size per iteration instead of removing elements) , coz when size is 1 , then it is already sorted . 
  int size = n;
    
    while(size!=1){  // OR size>1
      	int temp = arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        size=size-1;
        
        //DOWN-HEAPIFY  
         int parentIndex = 0;
         int leftChildIndex =  2*(parentIndex)+1;
         int rightChildIndex = 2*(parentIndex)+2;
        
        while(leftChildIndex<size){ 
           int minIndex = parentIndex;
            
            if(arr[minIndex]>arr[leftChildIndex]){
                minIndex=leftChildIndex;
            }
           
            if(rightChildIndex<size && arr[minIndex]>arr[rightChildIndex]){
                minIndex=rightChildIndex;
            }
                  if(minIndex == parentIndex){ 
                        break;
                    }
                    
                    int temp = arr[parentIndex];
                    arr[parentIndex]=arr[minIndex];
                    arr[minIndex]=temp;
                   
                        
                    parentIndex     = minIndex;
                   	leftChildIndex  = 2*(parentIndex)+1;
         		  	rightChildIndex = 2*(parentIndex)+2;
         } 
      }
  }


int main(){
    int arr[] = {2,33,1,-10,77,379,-300};
    inplaceHeapSort(arr,7);

    for(int i=0;i<7;i++)cout<<arr[i]<<" ";
}