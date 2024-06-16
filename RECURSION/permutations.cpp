#include<bits/stdc++.h>
using namespace std;              //no. of permutations = n!
                                  //duplicates allowed
void permute(vector<char> &vec, int start, int end){
    if(start==end){
        for(char i:vec)
        cout<<i;
        cout<<endl;
    }
    for(int j=start;j<=end;j++){
        swap(vec[start], vec[j]);
        permute(vec, start+1, end);
        swap(vec[start], vec[j]);  //backtracking
    }
}
int main(){
    vector<char> vec={'A', 'B', 'C', 'D'};
    int n=vec.size();
    permute(vec, 0, n-1);
    
    return 0;
}                         