#include<bits/stdc++.h>
using namespace std;          //generate power set using bitwise operators
                              //power set size = pow(2, n)
                              //counter=000...n  => 000.. => empty set while 0011.. => CD; 101.. => AC
void powerSet(char* set, int n){
    int powerSetSize=pow(2, n);
    for(int counter=0;counter<powerSetSize;counter++){     //counter binaryRepresentation runs 000 to 111

        for(int i=0;i<n;i++){
            int bitMask=1<<i;        //check if ith bit in counter is 1 or not
            if(counter&bitMask)      //if bit is set or bit is 1
            cout<<set[i];
        }
        cout<<endl;
    }
}
int main(){
    char set1[]={'A', 'B', 'C'};     //each position corresponds to the position in counter
    char set2[]={'A', 'B', 'C', 'D'};
    powerSet(set1, 3);
    powerSet(set2, 4);

    return 0;
}                                     //O(n*2^n)