#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void output(vi & coefs)
{
	int cs = coefs.size();
	cout << "(";
	for (int i = 0; i < cs; i++)
	{
		cout << coefs[i] << "x^" << cs - i - 1;
		if (i != cs - 1)
			cout << " + ";
	}
	cout << ")";
}

vi dissolve(vi & coefs, int x)
{
	// 1 2 -3 -4 4
	vi emp(0);
	vi res(coefs.size(), 0);
	for (int i = 0; i < res.size(); i++)
	{
		res[i] = res[max(0, i - 1)] * x + coefs[i];
	}
	if (res[res.size() - 1] == 0)
		return res;
	else
		return emp;
}

void ruffini(vi & coefs)
{
	if (coefs.size() == 2)
	{
		cout << coefs[0] << "x + " << coefs[1] << '\n';
		return;
	}

	int lastcoef = coefs[coefs.size() - 1];
	vi res;
	int fin;
	for (int x = -abs(lastcoef); x <= abs(lastcoef); x++)
	{
		if (x == 0)
			continue;
		res = dissolve(coefs, x);
		if (!res.empty())
		{
			res.pop_back();
			fin = x;
			break;
		}
	}
	if (res.empty())
	{
		output(coefs);
		return;
	}
	for (int x : res)
		cout << x << " ";
	cout << "(x + " << -fin << ")" << '\n';
	ruffini(res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int order;
	cin >> order;
	vi coefs(order + 1);
	for (int i = 0; i < order + 1; i++)
	{
		cin >> coefs[i];
	}
	ruffini(coefs);
	cout << '\n';
}