#include<bits/stdc++.h>
using namespace std;              //factorial of n

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);

}
int main(){
    int n=7;
    cout<<factorial(n)<<endl;
    
    return 0;
}                         