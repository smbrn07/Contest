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

int a[nmax], dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i];
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (i - 1 >= 0)
      dp[i] = min(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
    if (i - 2 >= 0)
      dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
  }
  cout << dp[n-1] << endl;
  return 0;
}
