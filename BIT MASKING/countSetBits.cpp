#include<bits/stdc++.h>
using namespace std;             //count total set bits
int main(){
    int n=9;

    int counter=0;

    while(n){
        counter += n&1;          //if last bit is 1
        n=n>>1;
    }

    cout<<counter;
}

/*
int setBits(int N){      //set the rightmost unset bit to set bit
    bool flag=false;
    int i=0, m=N;

    while(m){
        if((m&1)==0){
            flag=true;
            break;
        }
        m>>=1;
        i++;             //to store the position of rightmost set bit
    }
    if(!flag)
    return N;

    return N|(1<<i);     //set unset bit as 1
}
*/