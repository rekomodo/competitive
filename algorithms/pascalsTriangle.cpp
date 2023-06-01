#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void pascal(vvi &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        a[i] = vi(i + 1, 0);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}