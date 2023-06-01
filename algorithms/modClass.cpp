const ll MOD;

struct modint
{
    ll x;
    ll operator*(modint &a)
    {
        return x * a.x % MOD;
    }
    ll operator+(modint &a)
    {
        return (x + a.x) % MOD;
    }
    ll operator-(modint &a)
    {
        return (x - a.x + MOD) % MOD;
    }
    ll operator/(modint &a)
    {
        return x / a.x % MOD; // this doesn't really do anything
    }
};