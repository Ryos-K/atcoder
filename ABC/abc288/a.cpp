#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int main()
{
    int n, a[1009], b[1009];
    cin >> n;
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, n) cout << a[i] + b[i] << '\n';
    return 0;
}