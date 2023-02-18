#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define MOD modint998244353

int startwith(string s, string t) {
    int n = min(s.length(), t.length());
    int cnt = 0;
    rep(i, 0, n) {
        if (s[i] != t[i])
            break;
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> maxlcp(n, 0);
    vector<pair<string, int>> strs(n);
    rep(i, 0, n) {
        cin >> strs[i].first;
        strs[i].second = i;
    }
    sort(strs.begin(), strs.end());
    rep(i, 0, n - 1) {
        int cnt = startwith(strs[i].first, strs[i + 1].first);
        maxlcp[strs[i].second] = max(maxlcp[strs[i].second], cnt);
        maxlcp[strs[i + 1].second] = max(maxlcp[strs[i + 1].second], cnt);
    }
    rep(i, 0, n) cout << maxlcp[i] << " ";
    return 0;
}