#include<bits/stdc++.h>
using namespace std;    //count total how many times vowel occur in all substrings
int main(){
    string str="abced";
    int n=5;
    
    long long ans=0;
    for(int i=0;i<n;i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            long long count=(i+1)*(n-i);     //stores how many times a particular char occur in all substrings
            ans+=count;
        }
    }
    cout<<ans;
}