#include<bits/stdc++.h>                 //sum of n numbers
using namespace std;
void summ(int sum, int n){
    if(n<1){
        cout<<sum;
        return;
    }
    summ(sum+n, n-1);
}
int main(){
    summ(0, 6);
}