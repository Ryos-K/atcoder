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

int n, q;
V<set<int>> g;

int main()
{
    // code
    cin >> n >> q;
    g.resize(n);
    int independent = n;
    rep(i, 0, q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].insert(v);
            g[v].insert(u);
            if (g[u].size() == 1)
                --independent;
            if (g[v].size() == 1)
                --independent;
        }
        else
        {
            int v;
            cin >> v;
            --v;
            if (g[v].size() != 0)
            {
                fore(i, g[v])
                {
                    g[i].erase(v);
                    if (g[i].size() == 0)
                        ++independent;
                }
                g[v].clear();
                ++independent;
            }
        }
        cout << independent << "\n";
    }
    cout << endl;
    return 0;
}