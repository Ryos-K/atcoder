#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int n, m, c[19], tmp, cnt;
bool a[19][19], pttrn[19];

void reset_pttrn()
{
    rep(i, 0, 19)
    {
        pttrn[i] = false;
    }
}

int check_pttrn()
{
    rep(i, 1, n + 1)
    {
        if (!pttrn[i])
            return 0;
    }
    return 1;
}

int main()
{

    cin >> n >> m;
    rep(i, 0, m)
    {
        cin >> c[i];
        rep(j, 0, c[i])
        {
            cin >> tmp;
            a[i][tmp] = true;
        }
    }
    int all = 1 << m;
    rep(bit, 0, all)
    {
        reset_pttrn();
        rep(i, 0, m)
        {
            if ((bit >> i) % 2)
            {
                rep(j, 0, n + 1)
                {
                    pttrn[j] |= a[i][j];
                }
            }
        }
        // cout << std::bitset<10>(bit) << '\n';
        // rep(i, 1, n + 1)
        // {
        //     cout << pttrn[i] << " ";
        // }
        cnt += check_pttrn();
    }
    cout << cnt << endl;
    return 0;
}