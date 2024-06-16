#include<bits/stdc++.h>
using namespace std;         //find missing number
int main(){
    int arr[]={1, 2, 4, 5, 6}, n=6;              //3^3=0    
    int xor1=0, xor2=0;      

    for(int i=0;i<n-1;i++){
        xor2=xor2^arr[i];                       //xor2=1^2^4^5^6   xor1=1^2^3^4^5^6  => (1^1)^(2^2)^(3)^...(6^6) => 0^0^3^...^6 => 3
        xor1=xor1^(i+1);  //because indexing is done as 0, 1, 2, 3... so we can use that for xor of n values
    }
    xor1=xor1^n;

    cout<<(xor1^xor2)<<endl;
}