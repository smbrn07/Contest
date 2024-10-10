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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i];
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
      }
    }
  }
  cout << dp[n - 1];
  return 0;
}
