#include<bits/stdc++.h>
using namespace std;

int power(int base, int exp){
    if(exp==0)
    return 1;

    if(exp==1)
    return base;

    int temp=power(base, exp/2);
    if(exp%2==0)
    return temp*temp;
    else
    return base*temp*temp;
}
int main(){
    int base, exp;
    cout<<"Enter base: ";
    cin>>base;
    cout<<"Enter exponent: ";
    cin>>exp;
    cout<<endl;

    int result=power(base, exp);
    cout<<"Result: "<<result;
    return 0;
}