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
    // code
    int n, q;
    cin >> n >> q;
    int e, x;

    V<P<int, int>> range(n + 2);
    dsu d(n + 2);
    rep(i, 0, n + 2) range[i] = {-1, -1};

    rep(i, 0, q) {
        cin >> e;
        if (e == 2) {
            cin >> x;
            int l = x, r = x;
            if (range[d.leader(x - 1)].first != -1) {
                l = range[d.leader(x - 1)].first;
                d.merge(x, x - 1);
            }
            if (range[d.leader(x + 1)].second != -1) {
                r = range[d.leader(x + 1)].second;
                d.merge(x, x + 1);
            }
            range[d.leader(x)] = {l, r};
        } else if (e == 3) {
            if (range[d.leader(1)].second == -1) {
                cout << 1 << '\n';
            } else {
                cout << range[d.leader(1)].second + 1 << '\n';
            }
        }
    }
    return 0;
}