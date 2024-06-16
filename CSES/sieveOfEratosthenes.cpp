//The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n

#include<bits/stdc++.h>
using namespace std;
int main(){

    int n=110;

    if(n<=1)
    cout<<"0";

    vector<bool> prime(n, true);         //to keep check of no. being prime
    prime[0]=prime[1]=false;
    int counter=0;

    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(int j=i*i;j<n;j+=i)      //update multiples of prime as non-prime
            prime[j]=false;
        }
    }
    counter=count(prime.begin(), prime.end(), true);         //count prime
    cout<<counter;

    return 0;
}