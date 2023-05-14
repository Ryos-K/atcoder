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
    string s;
    ll n; // binary number
    ll s_num = 0;
    cin >> s >> n;
    int len = s.size();
    V<ll> addable;
    rep(i, 0, len)
    {
        if (s[i] == '?')
        {
            ll num = (1LL << (len - i - 1));
            addable.push_back(num);
            continue;
        }
        s_num += (s[i] - '0') * (1LL << (len - i - 1));
    }
#ifdef DEBUG
    cout << "s_num: " << s_num << endl;
    cout << "addable: ";
    veccout(addable);
    cout << endl;
#endif

    if (s_num > n)
    {
        cout << -1 << endl;
        return 0;
    }

    fore(i, addable)
    {
        if (s_num + i <= n)
        {
            s_num += i;
        }
    }
    cout << s_num << endl;
    return 0;
}