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
ll Hash[nmax];
int n;

ll binpow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binpow(a, b / 2) % mod;
  (res *= res) %= mod;
  if (b & 1)
    (res *= a) %= mod;
  return res;
}

ll gethash(int l, int r) {
  return (Hash[r] - Hash[l - 1] * binpow(10ll, 1ll * (r - l + 1)) + mod * mod) %
         mod;
}

void ok(int k, ll cur) {
  for (int i = k; i <= n; i += k) {
    // if (gethash(i - k + 1, i) != cur)
    //   return 0;
    cout << gethash(i - k + 1, i) << endl;
  }
  // return 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s;
  n = sz(s);
  s = ' ' + s;
  for (int i = 1; i <= n; ++i) {
    Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % mod;
  }
  int ans = n;
  cout << gethash(1, 3) << endl << endl;
  for (int i = 4; i <= 6; ++i)
    cout << s[i];
  cout << gethash(4, 6) << endl;
  // for (int i = 0; i <= n; ++i) {
  //   ll cur = gethash(1, 1 + i);
  //   if (ok(i, cur))
  //     ans = min(ans, i + 1);
  // }
  // cout << ans << endl;

  return 0;
}
