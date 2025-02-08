#include<bits/stdc++.h>
using namespace std;                           // count pairs their sum = sum%60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> mp;
        int pairs=0;
        for(auto x: time){
            int rem=x%60;
            int rem2=(60-rem)%60;
            pairs+=mp[rem2];
            mp[rem]++;
        }
        return pairs;
    }
};

int main(){
        Solution s;
        vector<int> time={30,20,150,100,40};
        cout<<s.numPairsDivisibleBy60(time);
}