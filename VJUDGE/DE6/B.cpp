#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e3 + 7;

int n, m, k, a[nmax][nmax];
ll dp[nmax][nmax];

ll calc(int x, int y, int u, int v) {
  return dp[u][v] - dp[u][y - 1] - dp[x - 1][v] + dp[x - 1][y - 1];
}

ll binsechy(int x, int y, int u, int v) {
  int l = y, r = v - 1, ans = y;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (calc(x, y, u, mid) < calc(x, mid + 1, u, v)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  ll res = abs(calc(x, y, u, ans) - calc(x, ans + 1, u, v));
  if (ans + 1 < v)
    res = min(res, calc(x, y, u, ans + 1) - calc(x, ans + 2, u, v));
  return res;
}

ll binsechx(int x, int y, int u, int v) {
  int l = x, r = u - 1, ans = x;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (calc(x, y, mid, v) < calc(mid + 1, y, u, v)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  ll res = abs(calc(x, y, ans, v) - calc(ans + 1, y, u, v));
  if (ans + 1 < u)
    res = min(res, abs(calc(x, y, ans + 1, v) - calc(ans + 2, y, u, v)));
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    }
  }
  while (k--) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    ll ans = calc(x, y, u, v);
    ans = min(binsechx(x, y, u, v), ans);
    ans = min(binsechy(x, y, u, v), ans);
    cout << ans << '\n';
  }
  return 0;
}
