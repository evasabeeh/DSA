#include <bits/stdc++.h>                         // optimized sieve of eratosthenes
using namespace std;
void sieve(int n){
    if (n <= 1)
        cout << "0";

    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int counter = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < n; j += i)
                prime[j] = false;
        }
    }
}
int main()
{

    int n = 110;
    sieve(n);

    return 0;
}