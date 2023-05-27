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

int main()
{
    // code
    int n, m;
    ll d;
    cin >> n >> m >> d;
    V<ll> a(n), b(m);
    veccin(a);
    veccin(b);
    sort(all(a));
    sort(all(b));
    ll ans = -1;
    int bi = m - 1;
    rrep(ai, n, 0)
    {
#ifdef DEBUG
        cout << "ai: " << ai << endl;
#endif
        while (bi >= 0 && a[ai] + d < b[bi])
        {
#ifdef DEBUG
            cout << "bi: " << bi << endl;
#endif
            --bi;
        }
        if (bi < 0)
            break;
        if (a[ai] - d > b[bi])
            continue;
#ifdef DEBUG
        cout << "ai: " << ai << endl;
        cout << "bi: " << bi << endl;
        cout << "a[ai]: " << a[ai] << endl;
        cout << "b[bi]: " << b[bi] << endl;
#endif
        ans = a[ai] + b[bi];
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}