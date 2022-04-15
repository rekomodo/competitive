#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int MAXN = 2e5;
int p[MAXN + 1], s[MAXN + 1];

int n, color[MAXN + 1], subtreeSize[MAXN + 1];
vvi adj;

void init()
{
    for (int i = 0; i <= MAXN; i++)
    {
        p[i] = i;
        s[i] = 1;
    }
}

int find(int x)
{
    while (p[x] != x)
        x = p[x];
    return x;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;

    if (s[a] > s[b])
        swap(a, b);

    s[b] += s[a];
    p[a] = b;
}

void dfsGetSize(int src, int p = -1)
{
    subtreeSize[src] = 1;
    for (int a : adj[src])
    {
        if (a == p)
            continue;
        dfsGetSize(a, src);
        subtreeSize[src] += subtreeSize[a];
    }
}

void dfsGetAns(int src, int p = -1)
{
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj = vvi(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}