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
    ll l, n1, n2, ans = 0;
    cin >> l >> n1 >> n2;
    V<int> v1(n1), v2(n2);
    V<ll> l1(n1), l2(n2);
    rep(i, 0, n1) cin >> v1[i] >> l1[i];
    rep(i, 0, n2) cin >> v2[i] >> l2[i];
    int i1 = 0, i2 = 0;
    P<ll, ll> pos1 = {0, l1[0]}, pos2 = {0, l2[0]}, range;
    while (1) {
        range = {max(pos1.first, pos2.first), min(pos1.second, pos2.second)};
        if (v1[i1] == v2[i2]) {
            ans += range.second - range.first;
        }
        if (pos1.second >= l && pos2.second >= l) {
            break;
        }
        if (pos1.second >= pos2.second) {
            ++i2;
            pos2.first = pos2.second;
            pos2.second += l2[i2];
        }
        if (pos1.second <= pos2.second) {
            ++i1;
            pos1.first = pos1.second;
            pos1.second += l1[i1];
        }
    }

    cout << ans << endl;
    return 0;
}