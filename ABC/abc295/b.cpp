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
int r, c;
V<string> b;

void bomb(int x, int y, int power) {
    if (y < r - 1)
        b[y + 1][x] = max((int)(b[y + 1][x]), power - 1 + '0');
    if (0 < y)
        b[y - 1][x] = max((int)(b[y - 1][x]), power - 1 + '0');
    if (x < c - 1)
        b[y][x + 1] = max((int)(b[y][x + 1]), power - 1 + '0');
    if (0 < x)
        b[y][x - 1] = max((int)(b[y][x - 1]), power - 1 + '0');
}
int main() {
    // code
    cin >> r >> c;
    b.resize(r);
    rep(i, 0, r) cin >> b[i];
    rep(k, 0, 9) {
        rep(i, 0, r) {
            rep(j, 0, c) {
                if ('1' <= b[i][j] && b[i][j] <= '9') {
                    bomb(j, i, b[i][j] - '0');
                }
            }
        }
    }
    rep(i, 0, r) {
        rep(j, 0, c) {
            if (b[i][j] == '#')
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}