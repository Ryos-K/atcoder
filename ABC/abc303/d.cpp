// clang-format off
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define fore(i, a) for (auto &i : a)
#define veccin(x) for (auto &i : x) std::cin >> i                                                          
#define veccout(x) for (auto &i : x) std::cout << i << " "
#define all(v) v.begin(), v.end()
#define chmax(a, b) ((a) < (b) ? (a = b, true) : false)
#define chmin(a, b) ((a) > (b) ? (a = b, true) : false)
#define INF 1e9
#define LINF 1e18
#define MOD 998244353
// clang-format on
// definition of variables
ll x, y, z;
V<V<ll>> dp;
string s;
void init()
{
    cin >> x >> y >> z;
    cin >> s;
    dp.resize(2, V<ll>(s.size()));
}

int main()
{
    // code
    init();
    if (s[0] == 'a')
    {
        dp[0][0] = x;
        dp[1][0] = z + y;
    }
    else
    {
        dp[0][0] = y;
        dp[1][0] = z + x;
    }
    int n = s.size();
    rep(i, 1, n)
    {
        if (s[i] == 'a')
        {
            dp[0][i] = min(dp[0][i - 1] + x, dp[1][i - 1] + z + x);
            dp[1][i] = min(dp[1][i - 1] + y, dp[0][i - 1] + z + y);
        }
        else
        {
            dp[0][i] = min(dp[0][i - 1] + y, dp[1][i - 1] + z + y);
            dp[1][i] = min(dp[1][i - 1] + x, dp[0][i - 1] + z + x);
        }
    }
    ll ans = min(dp[0][n - 1], dp[1][n - 1]);
    cout << ans << endl;
    return 0;
}