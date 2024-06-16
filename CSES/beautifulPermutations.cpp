//permutation of 1, 2,... n digits where no adjacent difference is 1
//for n=5 => 13524

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    
    if(n<=3)
    cout<<"No such permutation possible";
    else{
        int num=0;
        if(n%2==0){
            for(int i=1;i<n;i+=2)
            num=num*10+i;
            for(int i=2;i<=n;i+=2)
            num=num*10+i;
        }
        else{
            for(int i=1;i<=n;i+=2)
            num=num*10+i;
            for(int i=2;i<n;i+=2)
            num=num*10+i;
        }
        cout<<num;
    }
    return 0;
}