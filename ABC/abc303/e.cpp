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
int n;
V<set<int>> g;
set<int> unvisited;
V<int> end_points;
V<int> star;
V<int> star_levels;
void init()
{
    cin >> n;
    g.resize(n);
    rep(i, 0, n)
    {
        unvisited.insert(i);
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
}

void get_end_points()
{
    end_points.clear();
    rep(i, 0, n)
    {
        if (g[i].size() == 1)
        {
            end_points.push_back(i);
        }
    }
}

void get_star_levels()
{
    fore(v, star)
    {
        star_levels.push_back(g[v].size());
    }
}

void delete_star()
{
    fore(v, star)
    {
        fore(u, g[v])
        {
            fore(w, g[u])
            {
                if (w == v)
                {
                    continue;
                }
                g[w].erase(u);
            }
            g[u].clear();
        }
        g[v].clear();
    }
}

void get_star()
{
    star.clear();
    fore(v, end_points)
    {
        star.push_back(*(g[v].begin()));
    }
}

int main()
{
    // code
    init();
    rep(i, 0, n)
    {
        if (unvisited.find(i) == unvisited.end())
        {
            continue;
        }
        unvisited.erase(i);
        if (g[i].size() == 1)
        {
            continue;
        }
    }
    return 0;
}