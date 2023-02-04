#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

bool flg[200009];
ll n, m, cnt;
ll a, b;
vector<ll> G[200009];

void rec(int v, int pv)
{
    flg[v] = true;
    for (auto nv : G[v])
    {
        if (nv == pv)
            continue;
        if (flg[nv] == true)
        {
            cnt++;
            continue;
        }
        rec(nv, v);
    }
}
int main()
{

    cin >> n >> m;
    rep(i, 0, m)
    {
        cin >> a >> b;
        a++;
        b++;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, 1, n + 1)
    {
        if (flg[i])
            continue;
        rec(i, i);
    }
    int ans = cnt / 2;
    cout << ans << endl;

    return 0;
}