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

bool a[nmax][nmax];
ll f[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
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
  f[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j]) {
        if (i - 1 > 0)
          f[i][j] += f[i - 1][j], f[i][j] %= mod;
        if (j - 1 > 0)
          f[i][j] += f[i][j - 1], f[i][j] %= mod;
      } else
        f[i][j] = 0;
    }
  }
  cout << f[n][n] << endl;
  return 0;
}
