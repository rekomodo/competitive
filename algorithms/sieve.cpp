#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
#ifndef LOCALDEBUG
#define LOCALDEBUG false
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

vi primes;
vector<bool> isPrime;
void criba(int n)
{
    isPrime.resize(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
            continue;
        primes.pb(i);
        for (int m = 2; i * m <= n; m += 1 + m % 2)
            isPrime[i * m] = false;
    }
}