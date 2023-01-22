#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)

ll n, q;
ll a[309];
string s[309];
ll u[90009], v[90009];

ll num_via_line[309][309];
ll worth_max[309][309];
// bool line[309][309];

int main()
{
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> s[i];
    cin >> q;
    rep(i, 0, q) cin >> u[i] >> v[i];
    rep(i, 0, q)
    {
        u[i]--;
        v[i]--;
    }
    // rep(i, 0, n)
    // {
    //     rep(j, 0, n)
    //     {
    //         num_via_line[i][j] = 100000;
    //     }
    // }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (s[i][j] == 'N')
                continue;
            num_via_line[i][j] = 1;
            worth_max[i][j] = a[i] + a[j];
        }
    }

    rep(k, 0, n)
    {
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if (i == j)
                    continue;
                if (num_via_line[i][k] == 0 || num_via_line[k][j] == 0)
                    continue;
                if (num_via_line[i][j] == 0)
                {
                    num_via_line[i][j] = num_via_line[i][k] + num_via_line[k][j];
                    worth_max[i][j] = worth_max[i][k] + worth_max[k][j] - a[k];
                }
                if (num_via_line[i][j] > num_via_line[i][k] + num_via_line[k][j])
                {
                    num_via_line[i][j] = num_via_line[i][k] + num_via_line[k][j];
                    worth_max[i][j] = worth_max[i][k] + worth_max[k][j] - a[k];
                }
                if (num_via_line[i][j] == num_via_line[i][k] + num_via_line[k][j])
                {
                    if (worth_max[i][j] < worth_max[i][k] + worth_max[k][j] - a[k])
                    {
                        worth_max[i][j] = worth_max[i][k] + worth_max[k][j] - a[k];
                    }
                }
            }
        }
    }
    rep(i, 0, q)
    {
        if (num_via_line[u[i]][v[i]] == 0)
        {
            cout << "Impossible"
                 << "\n";
        }
        else
        {
            cout << num_via_line[u[i]][v[i]] << " " << worth_max[u[i]][v[i]] << "\n";
        }
    }
}
