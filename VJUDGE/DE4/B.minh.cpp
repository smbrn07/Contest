#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, M, a[nmax], b[nmax];

bool check(int mid) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int w = b[i] - a[i];
    int d = max(0, min(mid, b[i]) - a[i]);
    res += w - d;
    if (res >= M)
      return 1;
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("buildcol.INP", "r", stdin);
  freopen("buildcol.OUT", "w", stdout);
  cin >> n >> M;
  int l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    l = min(a[i], l), r = max(a[i], r);
    b[i] = max(b[i - 1], a[i]);
  }
  for (int i = n, cur = 0; i >= 1; --i) {
    cur = max(cur, a[i]);
    b[i] = min(b[i], cur);
  }
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
