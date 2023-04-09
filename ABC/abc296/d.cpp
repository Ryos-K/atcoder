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
#define chmax(a, b) ((a) < (b) ? (a = (b), true) : false)
#define chmin(a, b) ((a) > (b) ? (a = (b), true) : false)
#define INF 1e9
#define LINF 1e18
#define MOD 998244353
// clang-format on
void sol() {
    // code
}

V<ll> getprime(ll n) {
    V<ll> ret;
    V<bool> arr(n + 1, false);
    rep(i, 2, n + 1) {
        if (arr[i] == false) {
            ret.push_back(i);
            for (int j = 2; i * j <= n; ++j) {
                arr[i * j] = true;
            }
        }
    }
    // veccout(ret);
    return ret;
}

int main() {
    // code
    ll n, m;
    cin >> n >> m;
    if (m / n + (m % n ? 1 : 0) > n) {
        cout << -1 << endl;
        return 0;
    }
    if (n >= m) {
        cout << m << endl;
        return 0;
    }

    V<ll> primes = getprime(min(n, (ll)(2e6)));

    ll ans = LINF;
    // veccout(primes);
    fore(i, primes) {
        if ((m / i + (m % i ? 1 : 0)) / (n / i) +
                (((m / i + (m % i ? 1 : 0)) % (n / i)) ? 1 : 0) >
            n)
            continue;
        chmin(ans, (m / i + (m % i ? 1 : 0)) * i);
    }

    // ll i, j, ans;
    // i = j = sqrt(m);

    // j++;
    // ans = LINF;
    // while (1) {
    //     if (i * j == m) {
    //         ans = m;
    //         break;
    //     }
    //     if (i * j > m) {

    //         chmin(ans, i * j);
    //         j = max(j - 1, 0ll);
    //     } else {
    //         if (i == n)
    //             break;
    //         i = min(i + 1, n);
    //     }
    // }
    cout << ans << endl;

    return 0;
}