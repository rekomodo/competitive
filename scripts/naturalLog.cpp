#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

long double ln2 = 0.6931471805599453094172321214581765680755001343602552541206800094;

void getln2(int convergenceSteps)
{
    ln2 = 0;
    for (int i = 1; i <= convergenceSteps; i++)
    {
        long double quotient = 1 / (long double)i;
        ln2 += (i % 2 ? 1 : -1) * quotient;
    }
}

long double ln(long double x, long double convergenceSteps)
{
    long long n = 0;
    long long power2 = 1;
    while (power2 * 2 <= x)
    {
        n++;
        power2 *= 2;
    }

    long double xminus2n = 1;
    long double twoalphan = 1;
    long double res = n * ln2;
    for (int i = 1; i <= convergenceSteps; i++)
    {
        xminus2n *= (x - power2);
        twoalphan *= power2;
        long double quotient = xminus2n / (twoalphan * (long double)i);
        res += (i % 2 ? 1 : -1) * quotient;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double a, c;
    cin >> a >> c;
    cout.precision(17);
    long double res = ln(a, c);
    cout << res << '\n';
}