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
    int n = 8;
    string s;
    cin >> s;
    int b[2];
    int k;
    int r[2];
    int bi = 0;
    int ri = 0;

    rep(i, 0, n) {
        if (s[i] == 'B') {
            b[bi++] = i;
        }
        if (s[i] == 'R') {
            r[ri++] = i;
        }
        if (s[i] == 'K') {
            k = i;
        }
    }

    // cout << b[0] << " " << b[1] << " " << k[0] << " " << k[1] << " " << r
    //      << endl;

    if (b[0] % 2 == (b[1] + 1) % 2 && r[0] < k && k < r[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}