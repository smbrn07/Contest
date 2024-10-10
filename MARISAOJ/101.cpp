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
const int nmax = 500 + 7;

int n, m, k, a[nmax][nmax], f[nmax][nmax];

int cal(int x1, int y1, int x2, int y2) {
  return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int l = 1, r = 1; r <= m; ++r) {
        while (cal(j, l, i, r) > k && l <= r)
          ++l;
        if (cal(j, l, i, r) <= k)
          ans = max(ans, (r - l + 1) * (i - j + 1));
      }
    }
  }
  cout << ans << endl;

  return 0;
}
