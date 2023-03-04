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

vector<ll> cnt_prod;

void make_cnt_prod(int n) {
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if (i * j > n)
                break;
            cnt_prod[i * j]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    cnt_prod.resize(n + 1);
    make_cnt_prod(n);
    // veccout(cnt_prod);
    rep(i, 1, n) { ans += cnt_prod[i] * cnt_prod[n - i]; }
    cout << ans << endl;
    return 0;
}