#include<iostream>
#include<vector>
#include <algorithm>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
//  ####################################################################
    /* intialise a vector during interviews*/
    vector<int> v{5,7,3,1,8,4,4,33,44};

//  ####################################################################
    /* Find largest k or smalles k elements in O(n) */
    //four smallest values and four largest values
        vector<int>arr(100000,-1);
        int mn1=1e9,mn2 = 1e9, mn3 = 1e9, mn4 = 1e9;
        int mx1 = -1e9,mx2=-1e9, mx3 = -1e9, mx4 = -1e9;

        for(auto& ele: arr){
            if(ele< mn1){
                mn4=mn3; // order of these statements is v imp
                mn3=mn2;
                mn2=mn1;
                mn1= ele;
            }
            else if(ele < mn2){
                mn4=mn3;
                mn3=mn2;
                mn2=ele;
            }
            else if(ele<mn3){
                mn4=mn3;
                mn3=ele;
            }
             else if(ele<mn4){
                mn4=ele;
            }

            if(ele> mx1){
                mx4=mx3;
                mx3=mx2;
                mx2=mx1;
                mx1= ele;
            }
            else if(ele > mx2){
                mx4=mx3;
                mx3=mx2;
                mx2=ele;
            }
            else if(ele>mx3){
                mx4=mx3;
                mx3=ele;
            }
             else if(ele>mx4){
                mx4=ele;
            }
        }

//  ####################################################################
//  cool way for std::min      
 int mn = min({mx4-mn1,mx3-mn2,mx2-mn3,mx1-mn4}); // minimum of 4 values in one go

//  ####################################################################

/* traverse a map*/

 unordered_map<int,int> mp;
 mp[0]++;
 mp[1]++;

 for(auto& pair:mp){
    cout<<pair.first<<pair.second<<endl;
 }


}        