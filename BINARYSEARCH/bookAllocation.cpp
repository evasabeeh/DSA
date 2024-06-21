#include<bits/stdc++.h>
using namespace std;                      
                                    //allocate books to k students such that min books that can be distributed is maximum
bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++){
        if (pageSum + arr[i] <= mid)
        pageSum += arr[i];
        else{
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            return false;

            pageSum=0;
            pageSum += arr[i];
        }
        if (studentCount > m)
        return false;
    }
    return true;
}

int findPages(vector<int> arr, int n, int m)
{
    if (m > n)
    return -1;

    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    sum += arr[i];
    
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e){
        if (isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else
        s = mid + 1;
        
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main(){
    int n=4, m=2;
    vector<int> arr={12, 34, 67, 90};
    cout<<findPages(arr, n, m);
    return 0;
}

// https://www.naukri.com/code360/problems/allocate-books_1090540
// https://leetcode.com/problems/split-array-largest-sum/description/