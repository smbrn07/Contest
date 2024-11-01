#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e8 + 7;
const int nmax = 1e3 + 7;

int n, m;
char a[nmax][nmax];
ll dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == '1') {
        if (i - 1 > 0) {
          dp[i][j] += dp[i - 1][j], dp[i][j] %= mod;
        }
        if (j - 1 > 0) {
          dp[i][j] += dp[i][j - 1], dp[i][j] %= mod;
        }
      } else
        dp[i][j] = 0;
    }
  }
  cout << dp[n][m] % mod << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = 1e9 + 7;
    }
  }
  dp[1][1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == '1') {
        if (i - 1 > 0 && a[i - 1][j] == '1')
          dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
        if (j - 1 > 0 && a[i][j - 1] == '1')
          dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
      }
    }
  }
  cout << dp[n][m] << endl;

  return 0;
}
