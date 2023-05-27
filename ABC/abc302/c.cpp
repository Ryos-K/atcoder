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

V<V<int>> g;

bool is_diff_one(string s, string t, int m)
{
    int cnt = 0;
    rep(i, 0, m)
    {
        if (s[i] != t[i])
            cnt++;
    }
    return cnt == 1;
}

bool is_all_seen(int n, V<bool> &seen)
{
    rep(i, 0, n)
    {
        if (!seen[i])
            return false;
    }
    return true;
}

bool dfs(int start, int n, V<bool> &seen)
{
    if (seen[start])
        return true;
    seen[start] = true;
    if (is_all_seen(n, seen))
    {
        return true;
    }
    fore(next, g[start])
    {
        if (seen[next])
            continue;
        if (dfs(next, n, seen))
            return true;
    }
    return false;
}

int main()
{
    // code
    int n, m;
    cin >> n >> m;
    V<string> s(n);
    veccin(s);
    g.resize(n);
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            if (is_diff_one(s[i], s[j], m))
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
#ifdef DEBUG
    rep(i, 0, n)
    {
        cout << i << ": ";
        fore(j, g[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
#endif
    rep(i, 0, n)
    {
        V<bool> seen(n, false);

        if (dfs(i, n, seen))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}