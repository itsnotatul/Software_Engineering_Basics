#include<iostream>
#include<bitset>
using namespace std;

int main(){
bitset<32> bs(15);   
int n = 15;
  // bs(n);
for(int i=0;i<32;i++) cout<<bs[i]<<endl;
return 0;
}
