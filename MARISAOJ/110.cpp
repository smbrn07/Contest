#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const ll mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll binmul(ll a, ll b) {
  if (b == 0)
    return 0;
  ll res = binmul(a, b / 2) % mod;
  res = res + res % mod;
  if (b & 1)
    res = res + a % mod;
  return res;
}

ll binpow(ll a, ll b) {
  if (b == 0)
    return 1; // trong bai nay n=0 -> vo nghiem;
  ll res = binpow(a, b / 2) % mod;
  res = binmul(res, res) % mod;
  if (b & 1)
    res = binmul(res, a) % mod;
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll r4 = n / 3;
  ll r3 = n - r4;
  cout << binpow(3ll, r3) * binpow(4, r4) % mod;
  return 0;
}
