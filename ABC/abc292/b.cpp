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
int flg[109];
int main() {
    int n, q, x, t;

    cin >> n >> q;
    rep(i, 0, q) {
        cin >> t >> x;
        switch (t) {
        case 1:
            flg[x] += 1;
            break;
        case 2:
            flg[x] += 2;
            break;
        case 3:
            if (flg[x] >= 2)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        default:
            break;
        }
    }
    cout << endl;
    return 0;
}