#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

struct Trie
{
    struct node
    {
        node *children[26];
        bool wordEnd = false;
        node()
        {
            for (node *u : children)
                u = nullptr;
        }
    };
    node head;

    void insert(string word)
    {
        node *cur = &head;
        for (int i = 0; i < word.size(); i++)
        {
            int charIn = word[i] - 'a';
            node *childRef = cur->children[charIn];
            if (childRef == nullptr)
                childRef = new node();
            cur->children[charIn] = childRef;
            cur = childRef;
        }
        cur->wordEnd = true;
    }

    bool search(string word)
    {
        node *cur = &head;
        for (int i = 0; i < word.size(); i++)
        {
            int charIn = word[i] - 'a';
            node *childRef = cur->children[charIn];
            if (childRef == nullptr)
                return false;
            cur = childRef;
        }
        return cur->wordEnd;
    }

    bool startsWith(string prefix)
    {
        node *cur = &head;
        for (int i = 0; i < prefix.size(); i++)
        {
            int charIn = prefix[i] - 'a';
            node *childRef = cur->children[charIn];
            if (childRef == nullptr)
                return false;
            cur = childRef;
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}