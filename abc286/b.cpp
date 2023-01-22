#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cmp;
    rep(i, 0, n - 1)
    {
        if (s[i] == 'n' && s[i + 1] == 'a')
        {
            cout << "nya";
            i++;
        }
        else
        {
            cout << s[i];
        }
        cmp = i;
    }
    if (cmp != n - 1)
        cout << s[n - 1];
}