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
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    veccin(a);
    V<ll> ext(k);
    set<ll> st;
    st.insert(0);
    ll val = 0;
    rep(i, 0, k) {
        fore(j, a) { st.insert(val + j); }
        auto itr = st.upper_bound(val);
        val = *itr;
    }
    // veccout(st);
    copy_n(st.begin(), k + 1, ext.begin());

    cout << ext[k] << endl;

    return 0;
}