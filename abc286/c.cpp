#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)

int count_palindome(string s, int n, int first)
{
    int cnt = 0;
    int last = first + n - 1;
    while (first < last)
    {
        if (s[first] != s[last])
        {
            cnt++;
        }
        first++;
        last--;
    }
    return cnt;
}

int main()
{
    int n;
    ll a, b;
    string s, s_twi;
    ll min_cost = (1LL << 62) - 1;
    cin >> n >> a >> b >> s;

    s_twi = s + s;

    rep(i, 0, n - 1)
    {

        ll cost;
        if (min_cost > (cost = count_palindome(s_twi, n, i) * b + i * a))
        {

            min_cost = cost;
        }
    }
    cout << min_cost;
}
