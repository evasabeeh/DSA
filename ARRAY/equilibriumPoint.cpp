#include<bits/stdc++.h>             //equilibrium Index=sum before and sum after that idx is equal
using namespace std;

int main(){                        
    int a[]={1,3,5,2,2};
    int n=5;

    int prefix[n];
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=a[i];
        prefix[i]=sum;
    }
    sum=0;
    bool flag=false;
    for(int j=n-1;j>=2;j--){
        sum+=a[j];
        if(sum==prefix[j-2]){
            cout<<j<<endl;
            flag=true;
            break;
        }
    }
    if(!flag)
    cout<<"-1"<<endl;
    if(n==1)
    cout<<n<<endl;
}