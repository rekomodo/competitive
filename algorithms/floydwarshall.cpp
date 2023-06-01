#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
#ifndef LOCALDEBUG
#define LOCALDEBUG false
#endif
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;

struct Edge
{
    ll to, w;
};

const ll INF = 1e18;
vvi floydwarshall(vector<vector<Edge>> &adj)
{
    int n = adj.size() - 1;

    vvi d(n + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
        for (Edge e : adj[i])
            d[i][e.to] = min(d[i][e.to], e.w);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                ll newDist = d[i][k] + d[k][j];
                d[i][j] = min(d[i][j], newDist);
            }

    return d;
}