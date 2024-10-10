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
ll p[nmax], dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }
  for (int i = 1; i < n; ++i)
    dp[i][i + 1] = a[i] + a[i + 1];
  for (int i = 3; i <= n; ++i) {
    for (int j = i - 2; j >= 1; --j) {
      ll cur = 1e18;
      for (int k = j; k < i; ++k) {
        cur = min(cur, dp[j][k] + dp[k + 1][i]);
      }
      dp[j][i] = cur + p[i] - p[j - 1];
    }
  }
  cout << dp[1][n];
  return 0;
}
