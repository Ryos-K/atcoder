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
int n, m, x, y; // ax < ay
V<V<int>> g;
V<int> memo;
V<bool> flg;
int get_numchild(int pos) {
    if (memo[pos] != -1)
        return memo[pos];
    int maxchild = 0;
    fore(c, g[pos]) {
        int temp = get_numchild(c) + 1;
        chmax(maxchild, temp);
    }
    memo[pos] = maxchild;
    return maxchild;
};

int main() {

    cin >> n >> m;
    g.resize(n);
    memo.resize(n);
    flg.resize(n);

    rep(i, 0, n) memo[i] = -1;
    rep(i, 0, n) flg[i] = false;
    rep(i, 0, m) {
        cin >> x >> y;
        x--;
        y--;
        g[y].push_back(x);
    }
    rep(i, 0, n) { get_numchild(i); }
    rep(i, 0, n) {
        if (flg[memo[i]]) {
            cout << "No";
            return 0;
        }
        flg[memo[i]] = true;
    }
    cout << "Yes" << endl;

    rep(i, 0, n) { cout << (memo[i] + 1) << ' '; }
    cout << endl;

    return 0;
}