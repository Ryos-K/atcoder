#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)

bool cost[10009];
int main()
{
    int n, x;
    int a[59], b[59];
    cost[0] = true;
    cin >> n >> x;
    rep(i, 0, n)
    {
        cin >> a[i] >> b[i];
    }

    rep(a_i, 0, n)
    {
        rrep(cost_i, x, 0)
        {
            if (cost[cost_i])
            {
                rep(coin_num, 1, b[a_i] + 1)
                {
                    if (cost_i + coin_num * a[a_i] > x)
                        break;
                    cost[cost_i + coin_num * a[a_i]] = true;
                }
            }
        }
    }

    if (cost[x])
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
