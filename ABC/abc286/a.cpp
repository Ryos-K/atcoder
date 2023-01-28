#include <bits/stdc++.h>
#include <atcoder/all>
#define MOD 998244353
using namespace std;
typedef long long ll;

#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)

int main()
{
    int a[110];
    int p, q, r, s;
    int n;
    cin >> n >> p >> q >> r >> s;
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    rep(i, 1, p) cout << a[i - 1] << " ";
    rep(i, r, s + 1) cout << a[i - 1] << " ";
    rep(i, q + 1, r) cout << a[i - 1] << " ";
    rep(i, p, q + 1) cout << a[i - 1] << " ";
    rep(i, s + 1, n + 1) cout << a[i - 1] << " ";
}