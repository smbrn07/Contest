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

int c[1007], dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  for (int i = 1; i <= k; ++i)
    dp[i] = 1e9;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i - c[j] >= 0) {
        dp[i] = min(dp[i], dp[i - c[j]] + 1);
      }
    }
  }
  cout << (dp[k] == 1e9 ? -1 : dp[k]) << endl;
  return 0;
}
