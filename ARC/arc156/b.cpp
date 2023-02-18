#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define chmax(a, b) ((a) < (b) ? a = b : a)
#define chmin(a, b) ((a) > (b) ? a = b : a)
#define MOD 998244353
void sol() {}

ll fanc[200009];

void calc_fanc() {
    fanc[0] = fanc[1] = 1;
    rep(i, 2, 200009) fanc[i] = (fanc[i - 1] * i) % MOD;
}

ll calc_comb(int n, int k) {
    return (fanc[n] / inv_mod(fanc[n - k], MOD) / inv_mod(fanc[k], MOD));
}

int main() {
    calc_fanc();
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> vec;
    vec.push_back({a[0], a[0]});
    rep(i, 1, n) {
        if (vec.back().second == a[i] - 1)
            vec.back().second = a[i];
        else if (vec.back().second < a[i] - 1)
            vec.push_back({a[i], a[i]});
    };

    rep(i, 0, k) {
        if (vec[0].first != 0) {
            vec.insert(vec.begin(), {0, 0});
            continue;
        }
        ans += calc_comb()
    }

    return 0;
}