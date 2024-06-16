class Solution {           //find subarray of max product
public:
    int maxProduct(vector<int>& nums) {
        int mult=1, maxx=INT_MIN;
        for(int i: nums){
            mult*=i;

            if(mult>maxx)
            maxx=mult;

            if(mult==0)
            mult=1;
        }
        mult=1;
        reverse(nums.begin(), nums.end());
        for(int i: nums){
            mult*=i;

            if(mult>maxx)
            maxx=mult;

            if(mult==0)
            mult=1;
        }
        return maxx;
    }
};
int main(){
    Solution s;
    vector<int> nums={6,3,-2,4};
    cout<<s.maxProduct(nums);
}