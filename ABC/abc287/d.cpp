#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

string s, t;
bool frwd[300009], bkwd[300009];
int main()
{
    cin >> s >> t;
    int sl = s.length(), tl = t.length();

    rep(i, 0, tl)
    {
        if (s[sl - i - 1] == t[tl - i - 1] || t[tl - i - 1] == '?' || s[sl - i - 1] == '?')
        {
            bkwd[sl - i - 1] = true;
        }
        else
        {
            break;
        }
    }
    rep(i, 0, tl)
    {
        if (s[i] == t[i] || t[i] == '?' || s[i] == '?')
        {
            frwd[i] = true;
        }
        else
        {
            break;
        }
    }
    rep(i, 0, tl + 1)
    {
        if (i == 0)
        {
            if (bkwd[sl - tl])
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else if (i == tl)
        {
            if (frwd[tl - 1])
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            if (frwd[i - 1] && bkwd[i + sl - tl])
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}