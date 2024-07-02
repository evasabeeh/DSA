#include <bits/stdc++.h>
using namespace std;               // no. of ways to climb stairs starting from 0th stair taking either 1 or 2 steps

int solve(int n)
{
    if(n<0)
    return 0;
    
    if(n==0)
    return 1;

    return solve(n-1)+solve(n-2);           // to reach nth stair either you have come from n-1th stair or n-2th stair
}
int main()
{
    int n = 5;
    cout<<solve(n);

    return 0;
}
