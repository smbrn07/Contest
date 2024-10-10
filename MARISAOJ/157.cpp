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
const int nmax = 5e3 + 7;

int n, a[nmax];
ll pref[nmax], dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  for (int i = 1; i < n; ++i) {
    dp[i][i + 1] = a[i] + a[i + 1];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = i + 2; j <= n; ++j) {
      ll cur = 1e18;
      for (int k = i; k < j; ++k) {
        cur = min(cur, dp[i][k] + dp[k + 1][j]);
      }
      dp[i][j] = pref[j] - pref[i - 1] + cur;
    }
  }
  cout << dp[1][n];
  return 0;
}
