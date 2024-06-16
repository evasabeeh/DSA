#include<bits/stdc++.h>                 //sum of n numbers
using namespace std;
int sum(int n){
    if(n==0)
    return 0;

    return n+sum(n-1);
}
int main(){
    cout<<sum(6);
}


//each function call will return a value and all values will be added
//n+sum(5)+sum(4)+sum(3)+sum(2)+sum(1)+sum(0)

//sum(0) returns 0
//sum(1) returns 1+(0)
//sum(2) returns 2+(1)
//sum(3) returns 3+(3)....
//sum(6) returns 6+(15)