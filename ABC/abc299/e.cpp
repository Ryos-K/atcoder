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

int n, m, k;
V<V<int>> g;
V<P<int, int>> pd;
V<int> is_white;
V<V<int>> dist;
V<V<int>> point_match_dist;

bool fill_white(int p, int d, int from)
{
    if (is_white[p] == from)
        return false;
    if (d == 0 && is_white[p] >= 0)
    {
        cout << "No" << endl;
        cout << p << " " << from << endl;
        exit(EXIT_SUCCESS);
    }
    if (d == 0)
    {
        is_white[p] = -2;
        return true;
    }
    if (is_white[p] == -2)
    {
        cout << "No" << endl;
        cout << "is_white " << p << " " << from << endl;
        exit(EXIT_SUCCESS);
    }
    is_white[p] = from;
    bool ok = false;
    fore(to, g[p])
    {
        ok |= fill_white(to, d - 1, from);
    }
    return ok;
}

int main()
{
    // code

    cin >> n >> m;
    g.resize(n);
    is_white.resize(n);
    dist.assign(n, V<int>(n, INF));
    fill(all(is_white), -1);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> k;
    pd.resize(k);
    rep(i, 0, k)
    {
        int p, d;
        cin >> p >> d;
        p--;
        pd[i] = {p, d};
    }
    fore(p, pd)
    {
        if (!fill_white(p.first, p.second, p.first))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "b\n";
    if (k == 0)
    {
        cout << "Yes" << endl
             << 1;
        rep(i, 1, n) cout << 0;
        return 0;
    }
    bool ok = false;
    rep(i, 0, n)
    {
        if (is_white[i] == -2)
        {
            ok = true;
            break;
        }
    }
    cout << "a\n";
    if (!ok)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    fore(i, is_white)
    {
        if (i == -2)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}