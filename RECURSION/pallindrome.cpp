#include<bits/stdc++.h>
using namespace std;

bool pallindrome(string s, int start, int end){
    if(s[start]!=s[end])                     //anywhere if char does not match
    return false;

    if(start<end)
    return pallindrome(s, start+1, end-1);

    return true;
}
int main(){
    cout<<pallindrome("hello", 0, 4)<<endl;
    cout<<pallindrome("nitin", 0, 4)<<endl;
    return 0;
}                         