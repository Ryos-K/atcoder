#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int n, m, u, v;
vector<int> g[200009];
bool flg[200009];
bool rec(int n, int p)
{
    if (flg[n])
        return true;
    if (g[n].size() == 0 || g[n].size() > 2)
        return true;
    flg[n] = true;
    for (auto v : g[n])
    {
        if (p == v)
            continue;
        if (rec(v, n))
            return true;
    }
    return false;
}

int main()
{

    cin >> n >> m;

    rep(i, 0, m)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n != m + 1)
    {
        cout << "No";
        return 0;
    }
    if (rec(1, 1))
    {
        cout << "No";

        return 0;
    }
    rep(i, 1, n + 1)
    {
        if (flg[i] == false)
        {
            cout << "No";
            // cout << "tt";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}