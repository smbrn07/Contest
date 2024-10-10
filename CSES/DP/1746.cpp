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

int n, m, a[nmax];
ll dp[nmax][107];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  if (a[1] == 0)
    for (int i = 1; i <= m; ++i)
      dp[1][i] = 1;
  else
    dp[1][a[1]] = 1;

  for (int i = 2; i <= n; ++i) {
    if (a[i] == 0) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
        dp[i][j] %= mod;
      }
    } else {
      dp[i][a[i]] = dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1];
      dp[i][a[i]] %= mod;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans += dp[n][i];
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}
