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
int n, m;
V<V<int>> g;
V<V<int>> can_add_l;

int can_add(int from, int to) {

    if (can_add_l[from][to] != 0)
        return can_add_l[from][to];
    can_add_l[from][to] = 3;
    fore(v, g[from]) {
        if (v == to)
            continue;
        if (can_add_l[v][to] == 3)
            continue;
        if (can_add(v, to) == 1) {
            can_add_l[from][to] = 1;
            return 1;
        }
    }
    can_add_l[from][to] = 2;
    return 2;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    can_add_l.assign(n, V<int>(n, 0));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        can_add_l[u][v] = 1;
    }
    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j)
                continue;
            if (can_add(i, j) == 1) {
                ans++;
            }
        }
    }
    cout << (ans - m) << endl;
    // fore(a, can_add_l) {
    //     veccout(a);
    //     cout << endl;
    // }
    return 0;
}