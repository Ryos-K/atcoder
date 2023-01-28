#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

bool ends_with(const std::string &s, const std::string &suffix)
{
    if (s.size() < suffix.size())
        return false;
    return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}

int main()
{
    int n, m;
    string s[1009], t[1009];
    cin >> n >> m;
    rep(i, 0, n)
    {
        cin >> s[i];
    }
    rep(i, 0, m)
    {
        cin >> t[i];
    }
    int cnt = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (ends_with(s[i], t[j]))
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}