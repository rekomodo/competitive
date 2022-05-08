#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

struct DSU
{
    vi p, s;
    DSU(int size)
    {
        p = s = vi(size + 1);
        for (int i = 1; i <= size; i++)
        {
            p[i] = i;
            s[i] = 1;
        }
    }

    int find(int x)
    {
        while (x != p[x])
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
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}