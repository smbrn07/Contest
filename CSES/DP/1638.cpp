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
const int nmax = 1e3 + 7;

int n;
bool a[nmax][nmax];
ll dp[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      cin >> ch;
      if (ch == '.')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j]) {
        dp[i][j] += dp[i - 1][j], dp[i][j] %= mod;
        dp[i][j] += dp[i][j - 1], dp[i][j] %= mod;
      } else
        dp[i][j] = 0;
    }
  }
  cout << dp[n][n] << endl;
  return 0;
}
