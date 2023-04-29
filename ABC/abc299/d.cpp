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

int query(int i)
{
    cout << "? " << i << endl;
    int c;
    cin >> c;
    return c;
}

int main()
{
    // code
    int n;
    cin >> n;
    int l = 1, r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        int c = query(m);
        if (c == 0)
            l = m;
        else
            r = m;
    }
    cout << "! " << l << endl;
    return 0;
}