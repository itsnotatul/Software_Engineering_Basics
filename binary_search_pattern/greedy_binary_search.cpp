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

//example: allocate pages:
int check(int pages[], int n, int k, int page_limit){
    int cnt =1;
    int curr = 0;
    for(int i=0;i<n;i++){
        if(curr + pages[i] <= page_limit){
            curr += pages[i];
        }
        else {
            cnt++;
            curr = pages[i];
        }
    }
    return cnt <= k;
}

int findPages(int pages[], int n, int k) 
{
    if(n < k) return -1;
    int left =*max_element(pages,pages+n);
    int right = 0;
    for(int i=0;i<n;i++) right += pages[i];
    
    while(left<=right){
        int mid =left+(right-left)/2;
        
        if(check(pages,n,k,mid)) right = mid-1;
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


// example: aggressive cows

 int check(vector<int> &stalls, int n, int k, int dist_limit){
        int cnt =1;
        int prev =stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]- prev >=dist_limit){
                cnt++;
                prev = stalls[i];
            }
        }
        return cnt >= k;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int left = 0;
        int right = 1e9;
        while(left<=right){
            int mid = left +(right-left)/2;
            
            if(check(stalls,n,k,mid)) left = mid+1;
            else right = mid-1;
        }
        return right;
    }