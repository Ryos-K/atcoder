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

ll cnt;
set<int> st;
int a[10][10];
int h, w;
void rec(int x, int y) {
    if (st.count(a[x][y]))
        return;
    if (x == h - 1 && y == w - 1) {
        cnt++;
        return;
    }
    st.insert(a[x][y]);
    if (x < h)
        rec(x + 1, y);
    if (y < w)
        rec(x, y + 1);
    st.erase(a[x][y]);
}

int main() {
    cin >> h >> w;
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
    rec(0, 0);
    cout << cnt << endl;
    return 0;
}