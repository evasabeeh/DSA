#include<bits/stdc++.h>
using namespace std;                
int main(){
    vector<int> vec={7, 1, 8, 2, 4, 10, 3, 6};
    sort(vec.begin(), vec.end());   //ascending order
                                    //descending order: sort(vec.rbegin(), vec.rend())
    int freq=1, i=1;
    for(;i<vec.size();i++){
        if(vec[i]!=vec[i-1]){
            cout<<vec[i-1]<<" is repeated "<<freq<<" times"<<endl;
            freq=1;
        }
        else
        freq++;
    }
    cout<<vec[i-1]<<" is repeated "<<freq<<" times";
    return 0;
}