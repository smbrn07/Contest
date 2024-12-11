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
const int base = 31;

string s;
int k, n;
ll dp[nmax];

ll binpow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binpow(a, b / 2) % mod;
  (res *= res) %= mod;
  if (b & 1)
    (res *= a) %= mod;
  return res;
}

ll getHash(int l, int r) {
  return (dp[r] - dp[l - 1] * binpow(base, r - l + 1) + mod * mod) % mod;
}

bool ok(int len) {
  unordered_map<ll, int> mp;
  for (int i = 1; i <= n - len + 1; ++i) {
    if (++mp[getHash(i, i + len - 1)] >= k)
      return 1;
  }
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> k;
  n = sz(s);
  s = ' ' + s;
  for (int i = 1; i <= n; ++i) {
    dp[i] = (dp[i - 1] * base + s[i] - 'a' + 1) % mod;
  }
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}
