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

bool same(V<V<int>> a, V<V<int>> b, int n) {
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[i][j] == 1 && b[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // code
    int n;
    cin >> n;
    V<V<int>> a(n, V<int>(n)), b(n, V<int>(n)), a1(n, V<int>(n)),
        a2(n, V<int>(n)), a3(n, V<int>(n));
    fore(i, a) veccin(i);
    fore(i, b) veccin(i);
    rep(i, 0, n) {
        rep(j, 0, n) { a1[i][j] = a[n - 1 - j][i]; }
    }
    rep(i, 0, n) {
        rep(j, 0, n) { a2[i][j] = a1[n - 1 - j][i]; }
    }
    rep(i, 0, n) {
        rep(j, 0, n) { a3[i][j] = a2[n - 1 - j][i]; }
    }
    if (same(a, b, n) || same(a1, b, n) || same(a2, b, n) || same(a3, b, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}