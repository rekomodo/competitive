#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

//The sieve of erathosthenes is an N log(log(N)) algorithm to find all prime numbers up to N
//It's much more efficient than the N sqrt(N) trial division algorithm

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> table(n + 1, 1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(table[i] == false) continue;
        for (int j = 2; i*j <= n; j++)
        {
            table[i * j] = false;
        }
    }
    for (int i = 2; i < n + 1; i++)
    {
        if(table[i]) primes.pb(i);
    }
    return primes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int x : sieve(n))
        cout << x << '\n';
}