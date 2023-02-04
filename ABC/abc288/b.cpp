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
    int n, k;
    string s[109];
    map<string, bool> mp;
    cin >> n >> k;
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, k) mp[s[i]] = true;
    for (auto v : mp)
    {
        cout << v.first << '\n';
    }
    return 0;
}