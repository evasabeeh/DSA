#include<bits/stdc++.h>
using namespace std;
                                      // search in 2d matrix where rows and cols are all sorted in ascending order
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col])
            col--;
        else
            row++;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{ 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 }};
    cout << searchMatrix(matrix, 7);
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/