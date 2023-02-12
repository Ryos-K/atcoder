#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int n, m;
bool a[109];
int tmp;

int main()
{
    stack<int> st;
    cin >> n >> m;
    rep(i, 0, m)
    {
        cin >> tmp;
        a[tmp] = true;
    }

    rep(i, 1, n + 1)
    {
        st.push(i);
        if (!a[i])
        {
            while (st.size())
            {
                cout << st.top() << " ";
                st.pop();
            }
        }
    }

    return 0;
}