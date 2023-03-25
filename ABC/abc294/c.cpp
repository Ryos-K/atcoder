// clang-format off
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
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
#define INF 1e9+1
#define LINF 1e18
#define MOD 998244353
// clang-format on
void sol() {
    // code
}

int main() {
    // code
    int n, m;
    cin >> n >> m;
    V<int> a(n), b(m), ans_a, ans_b;
    veccin(a);
    veccin(b);
    a.push_back(INF);
    b.push_back(INF);
    int cnt = 1;
    auto itra = a.begin();
    auto itrb = b.begin();
    auto itra_last = --a.end();
    auto itrb_last = --b.end();
    while (!(itra == itra_last && itrb == itrb_last)) {
        if (*itra < *itrb) {
            ans_a.push_back(cnt++);
            ++itra;
        } else {
            ans_b.push_back(cnt++);
            ++itrb;
        }
    }
    veccout(ans_a);
    cout << endl;
    veccout(ans_b);
    return 0;
}