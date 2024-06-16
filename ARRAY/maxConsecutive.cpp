                                       // max. consecutive 1's after flipping 'm' 0's
#include<bits/stdc++.h>
using namespace std;

int traffic(int n, int m, vector<int> vehicle) {

	int start=0, end=0, len=0, count=0, maxx=0;

    for(;end<vehicle.size();end++){
        if(vehicle[end]==0)
        count++;

        if(count>m){
            if(vehicle[start]==0){
                start++;
                count--;
            }
            else
            start++;
        }
        len=end-start+1;
        maxx=max(maxx, len);
    }
    return maxx;
}

int main(){
    vector<int> v={1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1};
    int n=11, m=3;                         // m = no. of flips that 0 can be done to 1

    cout<<traffic(n, m, v);

    return 0;
}