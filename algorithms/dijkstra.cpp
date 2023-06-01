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

vector<ll> dijkstra(int src, vector<vector<Edge>> &adj)
{
    int n = adj.size() - 1;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<bool> visited(n + 1, false);
    vector<ll> d(n + 1, 1e17);

    q.push({0, src});
    d[src] = 0;

    while (!q.empty())
    {
        pii cur = q.top();
        q.pop();
        int from = cur.second;
        ll dist = cur.first;

        if (visited[from])
            continue;
        visited[from] = true;

        for (Edge e : adj[from])
        {
            ll newDist = dist + e.w;
            if (newDist < d[e.to])
            {
                q.push({newDist, e.to});
                d[e.to] = newDist;
            }
        }
    }

    return d;
}