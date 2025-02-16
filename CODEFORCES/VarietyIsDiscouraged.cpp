#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;  cin>>n;
        vector<int> vec(n, 0);
        for(int i = 0; i < n; i++){
            int k;  cin>>k;
            vec[i] = k;
        }

        map<int, int> mp;
        int ans = INT_MAX, l = 0, r = 0, maxx = 0;
        for(int i = 0; i < n; i++){
            if(mp.count(vec[i])){
                int left = mp[vec[i]] + 1, right = i - 1;
                int rem = right - left + 1;
                int total = n - rem;
                int dist = mp.size() - rem;
                
                if(total - dist >= maxx){
                    if (total < ans)
                    {
                        ans = total;
                        l = left;
                        r = right;
                    }
                    maxx = total - dist;
                }
                mp.clear();
            }
            mp[vec[i]] = i;
        }
        l++;
        r++;

        if(l > r)
        cout<<"0"<<endl;
        else
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}