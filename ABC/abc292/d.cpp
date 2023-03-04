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
int n, m, vn, en;
V<V<int>> g;
V<bool> flg;

void rec(int pos) {
    flg[pos] = true;
    vn++;
    en += g[pos].size();
    fore(v, g[pos]) {
        if (flg[v])
            continue;
        rec(v);
    }
}

int main() {
    int u, v;
    cin >> n >> m;
    g.resize(n);
    flg.resize(n, 0);
    rep(i, 0, m) {
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, 0, n) {
        if (flg[i])
            continue;
        rec(i);
        if (en == vn * 2)
            continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}