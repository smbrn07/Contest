#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const ll mod = 10ll;
const int nmax = 1e5 + 7;

ll binpow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binpow(a, b / 2) % mod;
  (res *= res) %= mod;
  if (b & 1)
    (res *= a) %= mod;
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b, c, d;
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> a >> b >> c >> d;
    cout << (binpow(a, b) + binpow(c, d)) % mod << endl;
  }

  return 0;
}
