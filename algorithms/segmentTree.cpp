#include <vector>
using namespace std;
#define pb push_back

template <class Node>
struct SegmentTree
{
    // generic segmentTree functions

    vector<Node> tree;
    int power2, treeSize;

    virtual Node merge(Node &a, Node &b) = 0;

    SegmentTree(int n)
    {
        power2 = 1;
        while (power2 < n)
            power2 *= 2;

        treeSize = 2 * power2 - 1;
        tree.resize(treeSize + 1, Node());
    }

    void update(int i, Node k)
    {
        int in = i + treeSize / 2;
        tree[in] = k;

        in /= 2;

        while (in > 0)
        {
            tree[in] = merge(tree[in * 2], tree[in * 2 + 1]);
            in /= 2;
        }
    }

    Node query(int i, int l, int r, int ql, int qr)
    {
        if (r < ql || l > qr)
            return Node();
        if (ql <= l && r <= qr)
            return tree[i];

        int mid = (l + r) / 2;
        Node q1 = query(i * 2, l, mid, ql, qr);
        Node q2 = query(i * 2 + 1, mid + 1, r, ql, qr);
        return merge(q1, q2);
    }

    Node query(int ql, int qr)
    {
        return query(1, 1, power2, ql, qr);
    }
};

struct MinNode
{
    int value = 1e9;
};

struct MinSegmentTree : SegmentTree<MinNode>
{
    MinSegmentTree(int n) : SegmentTree(n){};
    MinNode merge(MinNode &a, MinNode &b)
    {
        return (a.value < b.value ? a : b);
    }
};