#include<iostream>
#include<vector>
using namespace std;

int minSwap(int arr[], int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) cnt++; //4
    }
    cout<<cnt<<endl;
    int ret = INT_MAX; int tmp=0;
    for(int i=0;i<cnt;i++){
        if(arr[i] == 1) tmp++;
    }
    ret = min(ret,tmp);
    for(int i=1;i<n;i++){
        int en =i+cnt-1;
        tmp-=(arr[i-1] == 1)? 1: 0;
        if(arr[en%n] == 1) tmp++;
        ret = min(ret,tmp);
    }
    return ret;
}
// T:O(N)
// S:O(1)

int main(){
    int arr[6]= {0,0,0,1,1,0};
    cout<<minSwap(arr,6);
}