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
const int nmax = 5e3 + 7;

int f[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  int n = sz(a), m = sz(b);
  a = " " + a, b = " " + b;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j])
        f[i][j] = f[i - 1][j - 1] + 1;
      else
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
  }
  cout << abs(m - n) + min(m, n) - f[n][m];

  return 0;
}
