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

void memset_fibbonacci(vector<ll> &v, ll mod) {
    int n = v.size();
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i < n; ++i)
        v[i] = (v[i - 1] + v[i - 2]) % mod;
}

void memset_factorial(vector<ll> &v, ll mod) {
    int n = v.size();
    v[0] = v[1] = 1;
    for (int i = 2; i < n; ++i)
        v[i] = (v[i - 1] * i) % mod;
}

void memset_inverse_factorial(vector<ll> &v, ll mod) {
    int n = v.size();
    vector<ll> inv(n);
    inv[1] = v[0] = v[1] = 1;
    for (int i = 2; i < n; ++i) {
        inv[i] = mod - (inv[mod % i] * (mod / i)) % mod;
        v[i] = (v[i - 1] * inv[i]) % mod;
    }
}

struct Combination {
    vector<ll> fac, ifac, inv;
    ll mod;
    Combination(int n, ll mod) {
        fac.resize(n);
        ifac.resize(n);
        inv.resize(n);
        this->mod = mod;
        fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
        if (mod != 0) {
            for (int i = 2; i < n; ++i) {
                fac[i] = (fac[i - 1] * i) % mod;
                inv[i] = mod - (inv[mod % i] * (mod / i)) % mod;
                ifac[i] = (ifac[i - 1] * inv[i]) % mod;
            }
        } else {
            for (int i = 2; i < n; ++i) {
                fac[i] = (fac[i - 1] * i);
            }
        }
    }
    ll get_combination(int n, int k) {
        if (n < k)
            return 0;
        if (k < 0)
            return 0;
        if (mod != 0) {
            return fac[n] * (ifac[k] * ifac[n - k] % mod) % mod;
        } else {
            return (fac[n] / fac[n - k] / fac[k]);
        }
    }
};

int main() {
    Combination comb(20, 0);
    cout << comb.get_combination(5, 2);
    cout << endl;
    veccout(comb.fac);
    cout << endl;
    veccout(comb.ifac);

    return 0;
}