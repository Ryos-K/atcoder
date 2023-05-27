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

// 8 direction
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool find_snuck(int x, int y, int h, int w, V<string> &s, int dir)
{
    string snuck = "snuke";
    int len = snuck.size();
    rep(i, 0, len)
    {

        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            return false;
#ifdef DEBUG
        cout << "nx: " << nx << " ny: " << ny << " s[nx][ny]: " << s[nx][ny] << endl;
#endif
        if (s[nx][ny] != snuck[i])
            return false;
    }
    return true;
}

void cout_snuck_pos(int x, int y, int dir)
{
    string snuck = "snuke";
    int len = snuck.size();
    rep(i, 0, len)
    {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        cout << nx + 1 << " " << ny + 1 << endl;
    }
}

int main()
{
    // code
    int h, w;
    cin >> h >> w;
    V<string> s(h);
    veccin(s);
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            rep(dir, 0, 8)
            {
                if (find_snuck(i, j, h, w, s, dir))
                {
                    cout_snuck_pos(i, j, dir);
                    return 0;
                }
            }
        }
    }
    return 0;
}