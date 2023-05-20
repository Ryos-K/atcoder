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

int n, k;
V<int> a;
V<int> pos;

void reverse_lr(V<int> &a, int l, int r)
{
    reverse(a.begin() + l, a.begin() + r + 1);
}

void rec(int start)
{
#ifdef DEBUG
    cout << "start: " << start << endl;
#endif
    if (start == n - 1)
    {
        k -= n;
        if (k <= 0)
        {
            transform(all(a), a.begin(), [](int x)
                      { return x + 1; });
            veccout(a);
            cout << endl;
            exit(EXIT_SUCCESS);
        }
        return;
    }
    rep(i, 0, n)
    {
#ifdef DEBUG
        cout << "\t i: " << i << "\t pos: " << pos[i] << "\t k:" << k << endl;
#endif
        if (pos[i] == start)
        {
            rec(start + 1);
        }
        else if (pos[i] < start)
        {
            continue;
        }
        else
        {
            k--;
        }
        if (k <= 0)
        {
            transform(all(a), a.begin(), [](int x)
                      { return x + 1; });
            reverse_lr(a, start, pos[i]);
            veccout(a);
            cout << endl;
            exit(EXIT_SUCCESS);
        }
    }
}

int main()
{
    // code

    cin >> n >> k;
    a.resize(n);
    pos.resize(n);
    veccin(a);
    transform(all(a), a.begin(), [](int x)
              { return x - 1; });
    rep(i, 0, n) pos[a[i]] = i;
#ifdef DEBUG
    veccout(a);
    cout << endl;
    veccout(pos);
    cout << endl;
#endif
    rec(0);
    return 0;
}