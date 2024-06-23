#include<bits/stdc++.h>
using namespace std;                //rotate matrix by 90 degrees
int main(){
    vector<vector<int>> matrix={{4, 3, 5},{31, 7, 2}, {1, 6, 10}};

    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
        swap(matrix[i][j], matrix[j][i]);
    }
    for(int i=0;i<n;i++)
    reverse(matrix[i].begin(), matrix[i].end());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

   

// swap i,j with j,i then reverse rows