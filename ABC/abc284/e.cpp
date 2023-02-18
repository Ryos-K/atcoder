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
    int n, m, u, v;
    vector<vector<int>> g;
    cin >> n >> m;
    g.resize(n);
    rep(i, 0, m)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

        return 0;
}