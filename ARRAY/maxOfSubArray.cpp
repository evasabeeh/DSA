#include<bits/stdc++.h>                        //sliding window
using namespace std;

void maxSum(vector<int> nums, int k){          //print max of each subarrays of size k
                                               
    deque<int> dq(k);                          //stores indexes of the window elements
    for(int i=0;i<k;i++){
        while(!dq.empty()&&nums[i]>=nums[dq.back()]){   //if upcoming element is greater then pop
           dq.pop_back();                               //keeping queue in sorted manner of descending order
        }
        dq.push_back(i);
    }

    for(int i=k;i<nums.size();i++){
        cout<<nums[dq.front()]<<" ";                    //front element is the maximum element

        while(!dq.empty()&&dq.front()<=i-k){            //to remove indices out of the window
            dq.pop_front();
        }

        while(!dq.empty()&&nums[i]>=nums[dq.back()]){
           dq.pop_back();
        }
        dq.push_back(i);                                //upcoming element is smaller than back element
    }
    cout<<nums[dq.front()]<<" ";
}

int main(){
    vector<int> vec{6, 2, -1, 9, 2, 11, -4};
    int k=3;
    maxSum(vec, k);
    return 0;
}