#include<iostream>
using namespace std;         //time-O(n), space-O(1)
                             //Josephus Algo: n people are present in circle where at each step kth person is executed till only 1 is left
int josephus(int n, int k){
    if(n==1)
    return 0;

    return (josephus(n-1, k)+k)%n;
}
int main(){
    int n=7;                 //total people
    int k=3;                 //n-1 people to be skipped
    cout<<josephus(n, k)<<endl;

    return 0;
}