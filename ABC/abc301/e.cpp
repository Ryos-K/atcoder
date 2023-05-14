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

int h, w, t;                    // height, width, times
V<string> a;                    // map
V<P<int, int>> point(2);        // start, goal, and other
V<V<int>> dist(20, V<int>(20)); // distance
int cnt_o = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int from_x, int from_y, int from_no)
{
    queue<P<int, int>> q;
    q.push({from_x, from_y});
    V<V<bool>> dist_to(h, V<bool>(w, -1));
    dist_to[from_x][from_y] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (a[x][y] == 'S')
        {
            dist[0][from_no] = dist_to[x][y];
            dist[from_no][0] = dist_to[x][y];
        }
        else if (a[x][y] == 'G')
        {
            dist[1][from_no] = dist_to[x][y];
            dist[from_no][1] = dist_to[x][y];
        }
        else if (a[x][y] == 'o')
        {
            rep(i, 2, cnt_o + 2)
            {
                if (point[i].first != x || point[i].second != y)
                    continue;
                dist[i][from_no] = dist_to[x][y];
                dist[from_no][i] = dist_to[x][y];
            }
        }

        rep(i, 0, 4)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (a[nx][ny] == '#')
                continue;
            if (dist_to[nx][ny] != -1)
                continue;
            dist_to[nx][ny] = dist_to[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    // code
    cin >> h >> w >> t;
    a.resize(h);
    rep(i, 0, h) cin >> a[i];
    rep(i, 0, h) rep(j, 0, w)
    {
        if (a[i][j] == 'S')
            point[0] = {i, j};
        else if (a[i][j] == 'G')
            point[1] = {i, j};
        else if (a[i][j] == 'o')
        {
            cnt_o++;
            point.push_back({i, j});
        }
    }

    return 0;
}