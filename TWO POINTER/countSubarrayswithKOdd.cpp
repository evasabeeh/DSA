#include<bits/stdc++.h>
using namespace std;                            //count subarrays with k odd elements
int distinctSubKOdds(vector<int> &nums, int k)
{
	for(int i=0;i<nums.size();i++)
    nums[i]=(nums[i]%2==0)?0:1;                //make even elements as 0 and odd elements as 1
        
    int start=0, end=0, count=0, sum=0;

    while(end<nums.size()){
        sum+=nums[end];
        while(sum>k){
            sum-=nums[start];
            start++;
        }
        if(sum==k){
            count++;
            int temp=start;
            while(temp<end && nums[temp]==0){
                count++;
                temp++;
            }
        }
        end++;
	}
	return count;
}
int main(){
    vector<int> arr={5, 8, 5, 5, 1, 1, 8, 1, 2, 9, 6, 2, 1};
    cout<<distinctSubKOdds(arr, 3);
    return 0;
}