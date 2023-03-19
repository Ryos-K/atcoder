// clang-format off
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (ll)(m); --i)
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

bool isalleven(V<ll> x) {
    rep(i, 0, 3) if (x[i] % 2 != 0) return false;
    return true;
}
bool isallodd(V<ll> x) {
    rep(i, 0, 3) if (x[i] % 2 != 1) return false;
    return true;
}

ll sol() {
    V<ll> x(3), dx(2);
    veccin(x);
    if (!(isalleven(x) || isallodd(x)))
        return -1;
    if (x[0] == x[1] && x[1] == x[2])
        return 0;
    sort(all(x));
    rep(i, 0, 2) dx[i] = x[i + 1] - x[i];
    rep(i, 0, 3) dx[i] /= 2;
    if ((dx[0] + dx[1] * 2) % 3 != 0)
        return -1;
    if (dx[0] < dx[1] * 2) {
        return ((dx[0] + dx[1] * 2) / 3);
    }
    // cout << "aaaaa";
    ll ans = 0;
    ans += dx[1];
    dx[0] -= dx[1] * 2;
    dx[0] += dx[1];
    ans += (dx[0] / 3) * 2;
    return ans;
}

int main() {

    ll t;
    V<ll> a;
    cin >> t;
    rep(i, 0, t) { a.push_back(sol()); }
    veccout(a);

    return 0;
}