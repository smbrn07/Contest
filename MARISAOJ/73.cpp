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

int f[nmax][nmax], a[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      f[i][j] = f[i - 1][j + 1] + a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ll ans = 0;
      for (int l = 0; l <= k; ++l) {
        int cur_r = f[min(i + l, n)][max(j - k + l], cur_l = f[i - k + l - 1][j + l + 1];
        ans += cur_r - cur_l;
      }
      cout << ans << " ";
    }
    cout << endl;
  }

  return 0;
}
