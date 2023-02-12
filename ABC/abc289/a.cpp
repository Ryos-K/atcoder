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
    string s;
    cin >> s;
    int n = s.length();
    rep(i, 0, n)
    {
        cout << ((s[i] == '1') ? 0 : 1);
    }
    return 0;
}