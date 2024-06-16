#include<bits/stdc++.h>
using namespace std;

void oneToN(int n){   //print from 1 to n
    if(n==0){
        return;       //go down the recursive statement
    }
    oneToN(n-1);
    cout<<n<<" ";
}
void nToOne(int n){   //print from n to 1
    if(n==0){
        return;
    }
    
    cout<<n<<" ";
    nToOne(n-1);
}
int main(){
    oneToN(8);
    nToOne(8);
    
    return 0;
}                         