#include<bits/stdc++.h>
using namespace std;
void divisors(int n){
		for(int j=1;j<=sqrt(n);j++){
			if(n%j==0){
			   cout<<j<<" ";
			   if(j!=n/j)
			   cout<<n/j<<" ";
			}
		}
}

int main(){
    int n=36;
    divisors(n);
    return 0;
}