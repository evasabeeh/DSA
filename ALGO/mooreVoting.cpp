#include<bits/stdc++.h>
using namespace std;        //Moore's Voting Algo for find majority element(appears more than arr.size()/2 or arr.size()/3)
int main(){
    vector<int> arr={2, 3, 1, 3, 1, 3, 3, 4, 3, 2, 3, 3, 2, 2, 2, 3, 3};
    int counter=0;
    int element;

    for(int i: arr){
        if(counter==0){
            element=i;
            counter=1;
        }
        else if(i==element)
        counter++;
        else
        counter--;
    }
    counter=0;
    for(int i: arr){              //to verify that array has majority element else if prob says it must have majority element then this not needed.
        if(i==element)
        counter++;
    }
    if(counter>arr.size()/2)
    cout<<element;
    else
    cout<<"-1";
    return 0;
}