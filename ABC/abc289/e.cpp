#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int t;

int sol()
{
    int n, m, u, v;
    int c[2009];
    vector<int> g[2009];
    bool flg[2009];

    queue<pair<int, int>> q;
    cin >> n >> m;
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, m)
    {
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, 0, n)
        flg[i] = false;
    q.push(make_pair(0, 0));
    flg[0] = true;
    while (q.size())
    {

        auto now = q.front();
        q.pop();
        flg[now.first] = true;
        if (now.first == n - 1)
            return now.second;
        for (auto v : g[now.first])
        {
            if (flg[v])
                continue;
            if (c[now.first] == c[v])
                continue;
            q.push(make_pair(v, now.second + 1));
        }
    }
    return -1;
}

int main()
{
    cin >> t;
    // rep(i, 0, t)
    // {
    //     cout << sol() << '\n';
    // }
    // cout << endl;
    cout << sol() << endl;
    cout << sol() << endl;
    cout << sol() << endl;
    return 0;
}