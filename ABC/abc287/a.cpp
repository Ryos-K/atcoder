#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int main()
{
    int n;
    string s[100];
    cin >> n;
    rep(i, 0, n)
    {
        cin >> s[i];
    }
    int cntF = 0, cntA = 0;
    rep(i, 0, n)
    {
        if (s[i][0] == 'F')
        {
            cntF++;
        }
        else
        {
            cntA++;
        }
    }
    if (cntA > cntF)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    return 0;
}