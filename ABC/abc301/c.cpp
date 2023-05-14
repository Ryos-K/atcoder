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

bool is_transformable(char a)
{
    char transformable_chars[] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    rep(i, 0, 7)
    {
#ifdef DEBUG
        cout << a << " " << transformable_chars[i] << endl;
#endif
        if (a == transformable_chars[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // code
    string s, t;
    cin >> s >> t;
    int s_alpha_cnt[26];
    int s_wildcard_cnt = 0;
    int t_alpha_cnt[26];
    int t_wildcard_cnt = 0;
    fill(s_alpha_cnt, s_alpha_cnt + 26, 0);
    fill(t_alpha_cnt, t_alpha_cnt + 26, 0);
    int n = s.size();
    rep(i, 0, n)
    {
        if (s[i] == '@')
        {
            s_wildcard_cnt++;
        }
        else
        {
            s_alpha_cnt[s[i] - 'a']++;
        }
        if (t[i] == '@')
        {
            t_wildcard_cnt++;
        }
        else
        {
            t_alpha_cnt[t[i] - 'a']++;
        }
    }

#ifdef DEBUG
    rep(i, 0, 26)
    {
        cout << s_alpha_cnt[i] << " ";
    }
    cout << endl;
    rep(i, 0, 26)
    {
        cout << t_alpha_cnt[i] << " ";
    }
    cout << endl;
#endif
    rep(i, 0, 26)
    {
#ifdef DEBUG
        cout << i << " ";
#endif

        if (s_alpha_cnt[i] == t_alpha_cnt[i])
            continue;
        if (!is_transformable('a' + i))
        {
#ifdef DEBUG
            cout << "Not transformable" << endl;
#endif
            cout << "No" << endl;
            return 0;
        }
        if (s_alpha_cnt[i] < t_alpha_cnt[i])
        {
            if (s_wildcard_cnt >= t_alpha_cnt[i] - s_alpha_cnt[i])
            {
                s_wildcard_cnt -= (t_alpha_cnt[i] - s_alpha_cnt[i]);
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            if (t_wildcard_cnt >= s_alpha_cnt[i] - t_alpha_cnt[i])
            {
                t_wildcard_cnt -= (s_alpha_cnt[i] - t_alpha_cnt[i]);
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}