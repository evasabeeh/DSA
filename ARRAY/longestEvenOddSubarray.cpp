#include<bits/stdc++.h>              //longest subarray with alternating odd even elements
using namespace std;                 //even+odd=odd
void longestSubArray(vector<int> &vec){
    int maxx=0;
    int count=1;
    for(int i=0;i<vec.size()-1;i++){
        if((vec[i]%2==0&&vec[i+1]%2==1)||(vec[i]%2==1&&vec[i+1]%2==0))
        count++;
        else
        count=1;

        maxx=max(maxx, count);
    }
    cout<<maxx<<endl;
}
int main(){
    vector<int> vec={5, 1, 1, 6, 0, 9, 2, 1, 4, 9, 3};
    longestSubArray(vec);
    return 0;
}