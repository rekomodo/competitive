#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

struct Graph
{
    int N;
    vvi adj, revAdj, SCCVector;
    vi SCCid;
    Graph(int size)
    {
        adj = revAdj = vvi(size + 1);
        N = size;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    /*
    add elements to the stack in order of increasing exit time
    final stack has biggest exit time at the top
    */
    void dfs1(int src, stack<int> &S, vector<bool> &visited)
    {
        visited[src] = true;

        for (int a : adj[src])
        {
            if (visited[a])
                continue;
            dfs1(a, S, visited);
        }

        S.push(src);
    };

    void dfs2(int src, vi &component, vector<bool> &visited)
    {
        visited[src] = true;

        SCCid[src] = SCCVector.size();
        component.push_back(src);

        for (int a : revAdj[src])
        {
            if (visited[a])
                continue;
            dfs2(a, component, visited);
        }
    }

    void findSCC()
    {
        stack<int> nodesByExit;
        vector<bool> visited(N + 1, false);
        for (int i = 1; i <= N; i++)
        {
            if (visited[i])
                continue;
            dfs1(i, nodesByExit, visited);
        }

        SCCid = vi(N + 1, -1);
        visited = vector<bool>(N + 1, false);
        while (!nodesByExit.empty())
        {
            int cur = nodesByExit.top();
            nodesByExit.pop();
            if (visited[cur])
                continue;

            vi component;
            dfs2(cur, component, visited);
            SCCVector.push_back(component);
        }
    }
};

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.findSCC();

    cout << g.SCCVector.size() << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << g.SCCid[i] + 1 << " ";
    }
}