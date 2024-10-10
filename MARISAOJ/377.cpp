#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 100;
const int nmax = 5e3 + 7;

int n, a[nmax];
int p[nmax], dp[nmax][nmax], ind[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  memset(dp, 1000000007, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
    dp[i][i] = 0;
  }
  for (int i = 1; i < n; ++i)
    dp[i][i + 1] = a[i] * a[i + 1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      ind[j][i] = (p[i] - p[j - 1]) % mod;
    }
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = i - 2; j >= 1; --j) {
      for (int k = j; k < i; ++k) {
        dp[j][i] =
            min(dp[j][i], dp[j][k] + dp[k + 1][i] + ind[j][k] * ind[k + 1][i]);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}
