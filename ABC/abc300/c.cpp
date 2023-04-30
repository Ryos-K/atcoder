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

int is_cross(V<string> &c, int h, int w, int y, int x)
{
    if (c[y][x] == '.')
        return 0;
    int dist = 1;
    while (1)
    {
        if (y + dist >= h || x + dist >= w || y - dist < 0 || x - dist < 0)
            break;
        if (c[y + dist][x + dist] == '.' || c[y - dist][x - dist] == '.' || c[y + dist][x - dist] == '.' || c[y - dist][x + dist] == '.')
            break;
        dist++;
    }

    return dist - 1;
}

int main()
{
    // code
    int h, w, n;
    cin >> h >> w;
    n = min(h, w);
    V<string> c(h);
    V<int> cnt(n + 10);
    rep(i, 0, h)
    {
        cin >> c[i];
    }
    rep(i, 0, h) rep(j, 0, w)
    {

        cnt[is_cross(c, h, w, i, j)]++;
        // cout << is_cross(c, h, w, i, j) << endl;
    }

    rep(i, 1, n + 1)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}