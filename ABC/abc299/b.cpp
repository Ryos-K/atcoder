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
    int n, t;
    cin >> n >> t;
    V<int> c(n), r(n);
    veccin(c);
    veccin(r);
    bool exist_T = false;

    int player_No = 0;
    int max_val = 0;
    rep(i, 0, n)
    {
        if (c[i] == t)
        {
            exist_T = true;
            player_No = i;
            max_val = r[i];
            break;
        }
    }
    if (!exist_T)
    {
        t = c[0];
        max_val = r[0];
    }

    rep(i, 1, n)
    {
        if (c[i] == t)
        {
            if (chmax(max_val, r[i]))
            {
                player_No = i;
            }
        }
    }
    cout << player_No + 1 << endl;
    return 0;
}