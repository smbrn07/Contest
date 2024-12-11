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

int a[nmax], b[nmax], n, k, dp[nmax];

int binsech(int x) {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (mid <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    dp[i] = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] =
        max(dp[i], b[i] + dp[upper_bound(a + 1, a + n + 1, a[i] - k) - a - 1]);
    dp[i] = max(dp[i], dp[i - 1]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
