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
    int n;
    string s;
    cin >> n >> s;
    int ans = -1;
    int dango_num = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'o')
        {
            dango_num++;
        }
        else
        {
            chmax(ans, dango_num);
            dango_num = 0;
        }
    }
    dango_num = 0;
    rrep(i, n, 0)
    {
        if (s[i] == 'o')
        {
            dango_num++;
        }
        else
        {
            chmax(ans, dango_num);
            dango_num = 0;
        }
    }
    if (ans == 0)
    {

        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}