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
void sol() {
    // code
}

int main() {
    int n;
    cin >> n;
    V<int> a(n), b(n);
    V<V<ll>> dp(n, V<ll>(2, 0));
    rep(i, 0, n) cin >> a[i] >> b[i];
    dp[0][0] = dp[0][1] = 1;
    rep(i, 1, n) {
        if (a[i] != a[i - 1])
            dp[i][0] += dp[i - 1][0] % MOD;
        if (a[i] != b[i - 1])
            dp[i][0] += dp[i - 1][1] % MOD;
        if (b[i] != a[i - 1])
            dp[i][1] += dp[i - 1][0] % MOD;
        if (b[i] != b[i - 1])
            dp[i][1] += dp[i - 1][1] % MOD;
    }
    cout << ((dp[n - 1][0] + dp[n - 1][1]) % MOD) << endl;
    return 0;
}