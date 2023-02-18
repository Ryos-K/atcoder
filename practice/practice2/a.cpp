#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD 998244353

int main()
{
    int n, q;
    int t, u, v;
    cin >> n >> q;
    dsu d(n);
    rep(i, 0, q)
    {
        cin >> t >> u >> v;
        if (t)
        {
            cout << d.same(u, v) << endl;
        }
        else
        {
            d.merge(u, v);
        }
    }
    return 0;
}