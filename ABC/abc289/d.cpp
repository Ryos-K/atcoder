#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int n, m, x, tmp;
int a[19];
bool b[100009], dp[100009];

int main()
{
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cin >> m;
    rep(i, 0, m)
    {
        cin >> tmp;
        b[tmp] = true;
    }
    cin >> x;
    dp[0] = true;

    rep(i, 1, x + 1)
    {
        rep(j, 0, n)
        {
            if (i - a[j] < 0)
                continue;
            if (b[i])
                continue;
            if (dp[i - a[j]])
                dp[i] = true;
        }
    }
    cout << (dp[x] ? "Yes" : "No") << endl;

    return 0;
}