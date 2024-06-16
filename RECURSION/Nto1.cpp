#include<bits/stdc++.h>
using namespace std;
void fun(int x) {
    if(x==0)
    return;
    else{
        cout<<x<<" ";
        fun(x-1);
    }
}
int main(){
    fun(7);
    return 0;
}