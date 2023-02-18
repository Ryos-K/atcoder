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
    int n, q, t, p, x, l, r;
    vector<int> a(n);
    fenwick_tree<ll> fw(n);
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) fw.add(i, a[i]);
    rep(i, 0, q)
    {
        cin >> t;
        if (t)
        {
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
        else
        {
            cin >> p >> x;
            fw.add(p, x);
        }
    }
    return 0;
}