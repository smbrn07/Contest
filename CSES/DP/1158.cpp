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

int n, x, h[nmax], s[nmax], dp[100006];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i)
    cin >> h[i];
  for (int i = 1; i <= n; ++i)
    cin >> s[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = x; j >= h[i]; --j) {
      dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    }
  }
  cout << dp[x] << endl;
  return 0;
}
