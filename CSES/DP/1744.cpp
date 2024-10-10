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

int dp[507][507];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j)
      dp[i][j] = INT_MAX;
  }
  for (int i = 1; i <= 500; ++i)
    dp[i][i] = 0;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k < i; ++k)
        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
      for (int k = 1; k < j; ++k)
        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
    }
  }
  cout << dp[a][b];
  return 0;
}
