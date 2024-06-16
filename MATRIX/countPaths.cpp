#include<bits/stdc++.h>
using namespace std;                //you can move forward or downward
                                    //count no. of paths to reach cell (m, n) from (0, 0)
int countPaths(int m, int n){
    if(m==0||n==0)
    return 1;

    return countPaths(m-1, n)+countPaths(m, n-1);
}
int main(){
    cout<<countPaths(2, 2);
}

   
