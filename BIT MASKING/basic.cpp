2^2=0   //same bit xor=0
0^3=3



//decimal to binary
int i=0, ans=0;
while(n!=0){
    int bit=1&n;
    ans = (bit * pow(10, i))+ans;                   //store in string as int only ranges [-2^32, 2^32-1]
    n=n>>1;
    i++;
}   

-ve number to binary => 1's complement then add 1 => 2's complement

//binary to decimal
while(n!=0){
    int bit = n%10;
    n/=10;
    if (bit == 1)
    ans += pow(2, i);
}


//to check out of range
if(ans>INT_MAX*10 || ans<INT_MIN/10)              // if applying operations


//bitwise complement
int mask=0;                     //not valid for n=0
int m=n;
while(m!=0){
    mask = (mask<<1) | 1;            //mask size == size of bits of number
    m = m >> 1;
}
int ans = (~n) & mask;