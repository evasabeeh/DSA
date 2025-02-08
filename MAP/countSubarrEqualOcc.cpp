// https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1

// count subbaraysw= with equal occurences of x and y


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int xx = 0, yy = 0, ans = 0;
        map<int, int> mp;
        
        mp[0] = 1;
        for(int i: arr){
            if(i == x)
            xx++;
            
            if(i == y)
            yy++;
            
            int d = xx - yy;
            
            if(mp.find(d) != mp.end())
            ans += mp[d];
            
            mp[d]++;
        }
        return ans;
    }
};