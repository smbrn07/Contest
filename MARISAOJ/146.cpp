#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll dp[207][2007];

bool ok(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return 0;
  }
  return x > 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  vector<int> v;
  cin >> n >> k;
  for (int i = 2; i <= 2 * k; ++i)
    if (ok(i))
      v.pb(i);

  for (int j = 0; j <= k; ++j)
    dp[1][j] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int p = 0; p < sz(v); ++p) {
        if (v[p] - j <= k && v[p] <= 2 * k) {
          dp[i][j] += dp[i - 1][v[p] - j];
          dp[i][j] %= mod;
        }
      }
    }
  }
  ll ans = 0;
  for (int j = 0; j <= k; ++j) {
    ans += dp[n][j];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
