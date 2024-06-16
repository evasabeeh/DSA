#include<bits/stdc++.h>
using namespace std;          

void calc(char *set, int n, vector<char>&result){
    if(n==0){
        for(char i:result)
        cout<<i;
        cout<<endl;
        return;
    }
    result.push_back(set[n-1]);
    calc(set, n-1, result);
    result.pop_back();
    calc(set, n-1, result);
}
void powerSet(char* set, int n){
    vector<char> result;        //for temporary storage of subsets
    calc(set, n, result);
}
int main(){
    char set[]={'A', 'B', 'C', 'D'};
    powerSet(set, 4);
    
    return 0;
}                                     //O(2^n)