#include<bits/stdc++.h>
using namespace std;                //maximize the profit
                                    //if array is in decreasing order then no profit can be earned
int main(){
    vector<int> price={180, 225, 720, 100, 540, 675, 720};  //represents cost on each day
    int n=price.size();
  
    int i=0;
    while (i<n-1){
        //buy stock -> local minima
        while((i<n-1)&&(price[i+1]<=price[i])){ 
            i++;
        }
        if(i==n-1)
        break;
        
        int buy=i;
        i++;
        
        //sell stock -> local maxima
        while(i<n&&(price[i-1]<=price[i])){
            i++;
        }
        int sell=i-1;
        cout<<"Buy on day "<<buy<<" and Sell on day "<<sell<<endl;
    }

    return 0;
}
//time- O(n), space- O(1)