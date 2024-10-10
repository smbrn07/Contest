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

int n, x, c[107];
ll dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i - c[j] >= 0) {
        dp[i] += dp[i - c[j]];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[x];
  return 0;
}
