#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0)
    return a;

    gcd(abs(a-b), min(a, b));
}
int main(){
    cout<<gcd(20, 15);
    return 0;
}


//Euclidean algo: gcd(a, b)=gcd(a-b, b) where a>b