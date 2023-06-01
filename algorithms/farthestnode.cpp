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

vvi adj;
int dist[(int)1e5 + 1];

int maxDist = 0, leaf = -1;

void dfsFarthest(int src, int prev = -1, int dep = 0)
{
    dist[src] = max(dist[src], dep);

    if (dep > maxDist)
    {
        maxDist = dep;
        leaf = src;
    }

    for (int a : adj[src])
    {
        if (a == prev)
            continue;

        dfsFarthest(a, src, dep + 1);
    }
}

void getFarthest()
{
    dfsFarthest(1);
    dfsFarthest(leaf);
    dfsFarthest(leaf);
}