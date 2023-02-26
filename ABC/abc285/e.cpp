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
    V<int> a(n);
    V<ll> p(n + 1, 0), dp(n + 1, 0);
    veccin(a);
    rep(i, 2, n + 1) { p[i] = p[i - 1] + a[i / 2 - 1]; }
    rep(i, 0, n) {
        rep(j, 1, n + 1) {
            if (i + j > n)
                break;
            chmax(dp[i + j], dp[i] + p[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}