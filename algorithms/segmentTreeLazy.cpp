#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

struct node
{
    ll value;
    node(ll _value = 0) : value(_value) {}
};

struct segmentTree
{
    int size, power2 = 1;
    node nullNode = node();
    vector<node> tree;
    vector<ll> lazy;

    segmentTree(int n, node _nullNode)
    {
        nullNode = _nullNode;
        while (power2 < n)
            power2 *= 2;
        size = 2 * power2 - 1;
        tree = vector<node>(size + 1, _nullNode);
        lazy = vector<ll>(size + 1, 0);
    }

    virtual node merge(node &a, node &b) = 0;

    void update(int i, node v)
    {
        int in = i + size / 2;
        tree[in] = v;

        in /= 2;
        while (in > 0)
        {
            tree[in] = merge(tree[in * 2], tree[in * 2 + 1]);
            in /= 2;
        }
    }

    void update(int l, int r, int queryL, int queryR, int v, int i = 1)
    {
        pushLazy(i, l, r);

        if (l > queryR || r < queryL)
            return;
        if (queryL <= l && r <= queryR)
        {
            lazy[i] = v;
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, queryL, queryR, v, i * 2);
        update(mid + 1, r, queryL, queryR, v, i * 2 + 1);
    }

    virtual void pushLazy(int i, int l, int r) = 0;

    node query(int l, int r, int queryL, int queryR, int i = 1)
    {
        pushLazy(i, l, r);

        if (l > queryR || r < queryL)
            return nullNode;
        if (queryL <= l && r <= queryR)
            return tree[i];

        int mid = (l + r) / 2;
        node query1 = query(l, mid, queryL, queryR, i * 2);
        node query2 = query(mid + 1, r, queryL, queryR, i * 2 + 1);
        return merge(query1, query2);
    }
};

struct sumSegmentTree : segmentTree
{
    sumSegmentTree(int n, node _nullNode) : segmentTree(n, _nullNode) {}
    node merge(node &a, node &b)
    {
        return a.value + b.value;
    }

    void pushLazy(int i, int l, int r)
    {
        tree[i].value += lazy[i] * (ll)(r - l + 1);
        if (i * 2 <= size)
        {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
};

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    vi nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    sumSegmentTree sumTree = sumSegmentTree(n, node(0));
    for (int i = 1; i <= n; i++)
        sumTree.update(i, nums[i]);

    for (int i = 0; i < q; i++)
    {
        ll t, l, r, v;
        cin >> t;
        if (t == 2)
        {
            cin >> l;
            ll querySum = sumTree.query(1, sumTree.power2, l, l).value;
            cout << querySum << '\n';
        }
        else
        {
            cin >> l >> r >> v;
            sumTree.update(1, sumTree.power2, l, r, v);
        }
    }
}