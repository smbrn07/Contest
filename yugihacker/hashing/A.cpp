#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const ll mod = 1e9 + 7;
const int nmax = 1e6 + 7;
const int base = 97;

string s, t;
ll dp[nmax], HashT, p[nmax];

ll getHash(int l, int r) {
  return (dp[r] - dp[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  int n = sz(s), m = sz(t);
  s = ' ' + s, t = ' ' + t;
  p[0] = 1ll;
  for (int i = 1; i <= m; ++i) {
    p[i] = (p[i - 1] * base) % mod;
    HashT = (HashT * base + t[i] - 'a' + 1) % mod;
  }
  for (int i = 1; i <= n; ++i)
    dp[i] = (dp[i - 1] * base + s[i] - 'a' + 1) % mod;
  ll cnt = 0;
  for (int i = 1; i <= n - m + 1; ++i) {
    if (HashT == getHash(i, i + m - 1))
      ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
