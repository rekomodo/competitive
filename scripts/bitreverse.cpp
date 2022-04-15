#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int reverseBits(int x){
    int reverse = 0;
    for (int i = 0; i < 4; i++)
    {
        reverse += ((x & (1 << i)) > 0);
        if(i < 3) reverse = reverse << 1;
    }
    return reverse;
}