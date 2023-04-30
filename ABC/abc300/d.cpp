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
void sol()
{
    // code
}

bool is_prime(ll x)
{
    if (x <= 1)
        return false;
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void set_primes(V<ll> &primes, ll n)
{
    V<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    rep(i, 0, n)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

void set_cumsum_num_of_prime(V<ll> &cumsum, V<ll> &primes, ll n)
{
    cumsum[0] = 0;
    rep(i, 1, n + 1)
    {
        cumsum[i] = cumsum[i - 1];
        if (is_prime(i))
        {
            cumsum[i]++;
        }
    }
}

int main()
{
    // code
    ll n;
    cin >> n;

    // count the pattern a^2*b*c^2<=n

    V<ll> primes;
    V<ll> cumsum(1e6 + 1);
    set_primes(primes, 1e6 + 1);
    set_cumsum_num_of_prime(cumsum, primes, 1e6 + 1);

    // veccout(primes);
    ll ans = 0;
    auto itra = primes.begin();
    while (itra != primes.end())
    {
        ll a = *itra;
        if (a * a * a * a * a > n)
            break;
        auto itrb = itra;
        itrb++;
        while (itrb != primes.end())
        {

            ll b = *itrb;
            if (a * a * b * b * b > n)
                break;
            // ll c = sqrt(1.0f * n / (a * a * b));
            // if (b >= c)
            //     break;
            // ans += cumsum[c] - cumsum[b];

            auto itrc = itrb;
            itrc++;
            while (itrc != primes.end())
            {
                ll c = *itrc;
                if (a * a * b * c * c > n)
                    break;
                ans++;
                itrc++;
            }
            itrb++;
        }
        itra++;
    }
    cout << ans << endl;
    return 0;
}