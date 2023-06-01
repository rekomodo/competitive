#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

// 1-based LCA
struct tree
{
    int nodes;
    vvi adj;
    vi parent, depth, subtreeSize;
    tree(int _nodes) : nodes(_nodes)
    {
        adj = vvi(nodes + 1);
        parent = vi(nodes + 1);
        depth = subtreeSize = vi(nodes + 1, 0);
    }

    void initDFS(int src, int p = 0)
    {
        parent[src] = p;
        subtreeSize[src] = 1;
        depth[src] = depth[p] + 1;
        for (int a : adj[src])
        {
            if (a == p)
                continue;

            initDFS(a, src);
            subtreeSize[src] += subtreeSize[a];
        }
    }

    vvi lift;
    int power = 0;
    void initLift()
    {
        while ((1 << power) < nodes + 1)
            power++;
        power++;

        lift = vvi(nodes + 1, vi(power, 0));
        for (int i = 1; i <= nodes; i++)
            lift[i][0] = parent[i];

        for (int j = 1; j < power; j++)
            for (int i = 1; i <= nodes; i++)
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
    }

    int jump(int u, int mask)
    {
        for (int j = 0; j < power; j++)
            if ((1 << j) & mask)
                u = lift[u][j];
        return u;
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        if (depth[u] > depth[v])
            u = jump(u, depth[u] - depth[v]);
        if (u == v)
            return u;

        int lo = 0, hi = nodes, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (jump(u, mid) == jump(v, mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return jump(u, lo);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}