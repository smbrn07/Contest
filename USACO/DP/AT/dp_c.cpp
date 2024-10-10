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

int n, dp[3][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[0][i] = max(dp[1][i - 1] + b, dp[2][i - 1] + c);
    dp[1][i] = max(dp[0][i - 1] + a, dp[2][i - 1] + c);
    dp[2][i] = max(dp[0][i - 1] + a, dp[1][i - 1] + b);
  }
  cout << max({dp[0][n], dp[1][n], dp[2][n]});
  return 0;
}
