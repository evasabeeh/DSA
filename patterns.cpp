//pattern 1
#include<bits/stdc++.h>
using namespace std;
int main(){
    bool flag=0;
    for(int i=1;i<=5;i++){
        if(i%2==1)
        flag=1;

        for(int j=1;j<=i;j++){
            cout<<flag;
            flag=!flag;
        }
        cout<<endl;
    }
    return 0;
}


//pattern 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=4, k=1;i>=0;i--, k+=2){
        for(int j=1;j<=i;j++)
        cout<<" ";
        for(int j=1;j<=k;j++)
        cout<<"*";
        cout<<endl;
    }
    return 0;
}