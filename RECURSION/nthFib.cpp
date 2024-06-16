#include<bits/stdc++.h>
using namespace std;              //nth fibonacci term 

int nthFib(int n){
    if(n==0||n==1){
        return n;
    }
    return nthFib(n-2)+nthFib(n-1);  //0 is not considered

}
int main(){
    cout<<nthFib(4);
    
    return 0;
}                         