#include<iostream>
#include<vector>

#define MINM_POSSIBLE_ANSWER 0
#define MAXM_POSSIBLE_ANSWER 1e9
bool check(int x){
    // implemented depending on the problem
    return true;
}
//if looking for a minimum
int fun(){
    int left = MINM_POSSIBLE_ANSWER;
    int right = MAXM_POSSIBLE_ANSWER;

    while(left<=right){
        int mid = left +(right-left)/2;
        if(check(mid)){
            right = mid-1;// I want to find minimum so go for decreasing the answer
        }
        else left = mid+1;
    }
    return left;


}

// if looking for maximum
int fun(){
    int left = MINM_POSSIBLE_ANSWER;
    int right = MAXM_POSSIBLE_ANSWER;

    while(left<=right){
        int mid = left+(right-left)/2;

        if(check(mid)){
            left = mid+1; // I want to find the maximum, so go for increasing side
        }
        else right = mid-1;
    }
    return right;
}