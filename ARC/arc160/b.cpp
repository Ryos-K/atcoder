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
int pattern(int x, int y, int z)
{
    if (x == y && y == z)
        return 1;
    if (x == y || y == z || z == x)
        return 3;
    return 6;
}

ll sol(ll n)
{
    // code
    ll ans = 0;
    
}

int main()
{
    // code
    int t, n;
    cin >> t;
    rep(i, 0, t)
    {
        cin >> n;
        cout << sol(n) << "\n";
    }
    cout << endl;
    return 0;
}