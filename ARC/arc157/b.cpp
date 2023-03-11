// clang-format off
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define fore(i, a) for (auto &i : a)
#define veccin(x) for (auto &i : x) std::cin >> i                                                          
#define veccout(x) for (auto &i : x) std::cout << i << " "
#define all(v) v.begin(), v.end()
#define chmax(a, b) ((a) < (b) ? (a = b, true) : false)
#define chmin(a, b) ((a) > (b) ? (a = b, true) : false)
#define INF 1e9
#define LINF 1e18
#define MOD 998244353
// clang-format on
void sol() {
    // code
}

int cnt_x(string s) {
    int cnt = 0;
    fore(c, s) if (c == 'X') cnt++;
    return cnt;
}

int cnt_yy(string s, int n) {
    int cnt = 0;
    rep(i, 1, n) {
        if (s[i] == 'Y' && s[i - 1] == 'Y') {
            cnt++;
        }
    }
    return cnt;
}

void rev_xy(string &s) {
    fore(c, s) {
        if (c == 'X')
            c = 'Y';
        else
            c = 'X';
    }
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    cout << "Hello" << endl;

    int cntx = cnt_x(s);

    if (cntx == k) {
        cout << (n - 1);
        return 0;
    }

    if (cntx < k) {
        // rev_xy(s);
        k = n - k;
    }

    cntx = cnt_x(s);

    if (cntx == n) {
        cout << max(k - 1, 0);
        return 0;
    }

    V<int> vec;
    int cnt = 0;
    char pre = 'X';
    rep(i, 0, n) {
        if (s[i] == 'X') {
            cnt++;
        } else {
            if (pre == 'Y')
                continue;
            vec.push_back(cnt);
            cnt = 0;
        }
        pre = s[i];
        if (i == n - 1)
            vec.push_back(cnt);
    }

    if (vec.size() > 2) {
        sort(++vec.begin(), --vec.end());
        //  veccout(vec);
    }
    int size = vec.size();
    int bias = 0;
    rep(i, 1, size - 1) {
        if (vec[i] <= k) {
            bias += vec[i] + 1;
            k -= vec[i];
        } else {
            bias += k;
            k = 0;
        }
    }
    if (k > 0) {
        bias += k;
    }
    int cntyy = cnt_yy(s, n);
    cout << (cntyy + bias) << endl;

    return 0;
}