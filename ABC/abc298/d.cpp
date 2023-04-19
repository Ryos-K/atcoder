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
    ll q;
    cin >> q;
    V<V<ll>> rem(q + 1, V<ll>(10));
    ll ans = 1;
    int len = 1;
    rep(i, 0, 10) rem[0][i] = i;
    rep(i, 0, q) {
        rep(j, 0, 10) { rem[i + 1][j] = (rem[i][j] * 10) % MOD; }
    }

    list<int> s;
    s.push_back(1);

    rep(i, 0, q) {
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            ans = (ans * 10 + x) % MOD;
            len++;
            s.push_back(x);
        } else if (t == 2) {
            ans = (ans - rem[len - 1][s.front()] + MOD) % MOD;
            len--;
            s.pop_front();
        } else {
            cout << ans << "\n";
        }
    }
    cout << endl;

    return 0;
}