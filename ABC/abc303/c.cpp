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
int n, m, h, k;
string s;
set<P<int, int>> items;
void init()
{
    cin >> n >> m >> h >> k;
    cin >> s;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        items.insert(P<int, int>(x, y));
    }
}

int main()
{
    // code
    init();
    int x, y;
    x = y = 0;
    fore(i, s)
    {
        if (i == 'U')
        {
            y++;
        }
        else if (i == 'D')
        {
            y--;
        }
        else if (i == 'L')
        {
            x--;
        }
        else if (i == 'R')
        {
            x++;
        }
        h--;
        if (h < 0)
        {
            cout << "No" << endl;
            return 0;
        }
        if (items.find(P<int, int>(x, y)) != items.end())
        {
            if (h < k)
            {
                items.erase(P<int, int>(x, y));
                h = k;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}