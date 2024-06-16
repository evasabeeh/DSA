#include<bits/stdc++.h>
using namespace std;

void binary(int n){
    if(n>1)
    binary(n/2);

    cout<<n%2;
}
int main(){
    int n=11;
    binary(11);
}