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
void sol()
{
    // code
}

bool is_same_with_shift(V<string> &a, V<string> &b, int h, int w, int sh, int sw)
{
    rep(i, 0, h) rep(j, 0, w) if (a[i][j] != b[(i + sh) % h][(j + sw) % w]) return false;
    return true;
}

int main()
{
    // code
    int h, w;
    cin >> h >> w;
    V<string> a(h), b(h);
    rep(i, 0, h) cin >> a[i];
    rep(i, 0, h) cin >> b[i];
    rep(i, 0, h) rep(j, 0, w) if (is_same_with_shift(a, b, h, w, i, j))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}