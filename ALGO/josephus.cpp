#include<iostream>
using namespace std;         //time-O(n), space-O(1)
                             //Josephus Algo: n people are present in circle where at each step kth person is executed till only 1 is left
int josephus(int n, int k){
    int i=1, ans=0;
    while(i<=n){
        ans=(ans+k)%i;
        i++;
    }
    return ++ans;
}
int main(){
    int n=7;                 //total people
    int k=3;                 //k-1 people to be skipped
    cout<<josephus(n, k)<<endl;

    return 0;
}