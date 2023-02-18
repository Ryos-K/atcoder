#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define chmax(a, b) ((a) < (b) ? a = b : a)
#define chmin(a, b) ((a) > (b) ? a = b : a)
#define MOD 998244353

int cnt_front(string s, int n) {
    int cnt = 0;
    rep(i, 0, n) if (s[i] == '1') cnt++;
    return cnt;
}
bool is_neighbor_front(string s, int n) {
    rep(i, 0, n - 1) if (s[i] == '1' && s[i + 1] == '1') return true;
    return false;
}

int sol() {
    int n, cnt;
    string s;
    cin >> n >> s;
    cnt = cnt_front(s, n);
    if (n == 3) {
        if (s[0] == '0' && s[1] == '0' && s[2] == '0')
            return 0;
        if (s[0] == '1' && s[1] == '0' && s[2] == '1')
            return 1;
        return -1;
    }
    if(n == 4 && s[0] == '0' && s[1] == '1' && s[2] == '1' && s[3] == '0') return 3;
     
    if (cnt % 2 == 1)
        return -1;
    if (cnt == 2) {
        if (is_neighbor_front(s, n))
            return 2;
        else
            return 1;
    }
    return (cnt / 2);
}

int main() {
    int t;
    cin >> t;
    
    rep(i, 0, t) { cout << sol() << '\n'; }
    cout << endl;
    return 0;
}