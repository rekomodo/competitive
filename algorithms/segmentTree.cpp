#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

// segment tree implementation my way, max segment tree will be used for example

const int INF = 1e9;

struct node
{
    int value;
    node(int _value = -INF) : value(_value) {}
};

struct segmentTree
{
    int size, power2 = 1;
    node nullNode = node();
    vector<node> tree;

    segmentTree(int n, node _nullNode)
    {
        nullNode = _nullNode;
        while (power2 < n)
            power2 *= 2;
        size = 2 * power2 - 1;
        tree = vector<node>(size + 1, _nullNode);
    }

    virtual node merge(node &a, node &b)
    {
        return node();
    }

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

    node query(int l, int r, int queryL, int queryR, int i = 1)
    {
        if (l > queryR || r < queryL)
            return nullNode;
        if (queryL <= l && r <= queryR)
        {
            return tree[i];
        }

        int mid = (l + r) / 2;
        node query1 = query(l, mid, queryL, queryR, i * 2);
        node query2 = query(mid + 1, r, queryL, queryR, i * 2 + 1);
        return merge(query1, query2);
    }
};

struct maxSegmentTree : segmentTree
{
    maxSegmentTree(int n, node _nullNode) : segmentTree(n, _nullNode) {}
    node merge(node &a, node &b)
    {
        return max(a.value, b.value);
    }
};

struct sumSegmentTree : segmentTree
{
    sumSegmentTree(int n, node _nullNode) : segmentTree(n, _nullNode) {}
    node merge(node &a, node &b)
    {
        return a.value + b.value;
    }
};

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vi nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    maxSegmentTree maxTree = maxSegmentTree(5, node(-1e9));
    sumSegmentTree sumTree = sumSegmentTree(5, node(0));
    for (int i = 1; i <= n; i++)
    {
        maxTree.update(i, nums[i]);
        sumTree.update(i, nums[i]);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int queryMax = maxTree.query(1, maxTree.power2, l, r).value;
            int querySum = sumTree.query(1, sumTree.power2, l, r).value;

            auto print = [&l, &r](string type, int result)
            {
                cout << type << ' ' << l << '-' << r << " : " << result << '\n';
            };

            print("max", queryMax);
            print("sum", querySum);
        }
        else
        {
            maxTree.update(l, r);
            sumTree.update(l, r);
            cout << "update A[" << l << "] := " << r << '\n';
        }
    }
}