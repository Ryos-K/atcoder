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
// definition of variables
int n, m;
V<V<int>> a;
void init()
{
    // console input to variables
    cin >> n >> m;
    a.resize(m);
    rep(i, 0, m)
    {
        a[i].resize(n);
        veccin(a[i]);
        transform(all(a[i]), a[i].begin(), [](int x)
                  { return x - 1; });
    }
}

int main()
{
    // code
    init();
    V<V<bool>> ans(n, V<bool>(n, false));
    rep(i, 0, m)
    {
        rep(j, 0, n - 1)
        {
            ans[a[i][j]][a[i][j + 1]] = true;
            ans[a[i][j + 1]][a[i][j]] = true;
        }
    }
    int cnt = 0;
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            if (!ans[i][j])
                cnt++;
        }
    }
    cout << cnt << endl;
}