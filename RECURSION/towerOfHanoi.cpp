#include<iostream>
using namespace std;              //O(2^n)

void tower(int n, char from, char help, char to){
    if(n==0)
    return;

    tower(n-1, from, to, help);
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    tower(n-1, help, from, to);
}
int main(){
    int n=3;         //no. of disks
    tower(n, 'A', 'B', 'C');
    return 0;
}