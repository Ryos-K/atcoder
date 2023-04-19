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
#define INF 1e9
#define LINF 1e18
#define MOD 998244353
// clang-format on
void sol() {
    // code
}

int main() {
    // code
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    V<ll> va(101), vb(101), fina(102), finb(102);
    va[a] = 1, vb[b] = 1;
    int cnt = 0;
    bool flga, flgb;
    flga = flgb = false;
    while (1) {
        rrep(i, n, 0) {
            if (va[i] != 0) {
                flga = true;
                rep(j, 1, p + 1) {
                    if (i + j >= n) {
                        fina[cnt] += va[i];
                        continue;
                    }
                    va[i + j] += va[i];
                    va[i] = 0;
                }
            }

            if (vb[i] != 0) {
                flgb = true;
                rep(j, 1, p + 1) {
                    if (i + j >= n) {
                        finb[cnt] += vb[i];
                        continue;
                    }
                    vb[i + j] += vb[i];
                    vb[i] = 0;
                }
            }
        }
        if(flga == false && flgb == false) break;
        cnt++;
    }


    return 0;
}