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
const int nmax = 1e6 + 7;

int n, dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= 9; ++i)
    dp[i] = 1;
  for (int i = 10; i <= n; ++i)
    dp[i] = INT_MAX;
  for (int i = 10; i <= n; ++i) {
    int cur = i;
    while (cur != 0) {
      int x = cur % 10;
      cur /= 10;
      dp[i] = min(dp[i], dp[i - x] + dp[x]);
    }
  }
  cout << dp[n];
  return 0;
}
