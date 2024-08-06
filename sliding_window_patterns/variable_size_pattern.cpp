#include<iostream>
using namespace std;

int fun(string s){
    int n = s.size();
    int freq[256]; 
    memset(freq,0,sizeof(freq)); // important step

    int i=0,j=0;
    int ret =0;
    for(;j<n;j++){
        freq[s[j]]++;

        while(freq[s[j]]>1){
            freq[s[i]]--;
            i++;
        }
        ret = max(ret,j-i+1);
    }

    return ret;
     
}