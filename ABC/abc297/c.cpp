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
    int h, w;
    cin >> h >> w;
    V<string> s(h);
    veccin(s);

    rep(i, 0, h) rep(j, 0, w) {
        if (s[i][j] == 'T' && s[i][j + 1] == 'T') {
            s[i][j] = 'P';
            s[i][j + 1] = 'C';
        }
    }
    rep(i, 0, h) { cout << s[i] << '\n'; }
    cout << endl;
    return 0;
}