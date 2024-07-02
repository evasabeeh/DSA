#include<bits/stdc++.h>
using namespace std;              //fibonacci series upto n terms

void printFib(int a, int b, int n){
    if(n==0){
        cout<<a<<" ";
        return;
    }
    
    cout<<a<<" ";
    printFib(b, a+b, n-1);

}
int main(){
    int n=7;
    printFib(0, 1, n-1);
    
    return 0;
}                         


/*int fib(int n){             // find nth fibonacci number
    if(n==0)
    return 0;

    if(n==1)
    return 1;

    return fib(n-1)+fib(n-2);          // f(n)=f(n-1)+f(n-2)
}