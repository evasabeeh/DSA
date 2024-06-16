#include<bits/stdc++.h>
using namespace std;
void secondLargest(vector<int> arr, int n){
    int maxx=arr[0], maxx2=INT_MIN, minn=arr[0], minn2=INT_MAX;
    for(int i: arr){
        if(i<minn){
            minn2=minn;
            minn=i;
        }
        if(i>minn&&i<minn2)
        minn2=i;

        if(i>maxx){
            maxx2=maxx;
            maxx=i;
        }
        if(i<maxx&&i>maxx2)
        maxx2=i;
    }
    cout<<"Second largest: "<<maxx2<<endl;
    cout<<"Second smallest: "<<minn2;
}
int main(){
    vector<int> arr={5, 8, 5, 5, 1, 1, 8, 1, 2, 9, 6, 2, 1};
    int n=13;
    secondLargest(arr, n);
    return 0;
}