#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 2e6 + 7;

int f[nmax];

void timuoc(int x) {
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ++f[i];
      if (i * i != x)
        ++f[x / i];
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("stem.inp", "r", stdin);
  freopen("stem.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    timuoc(x);
  }
  int ans = 0;
  for (int i = 1; i <= nmax; ++i) {
    ans = max(ans, i * f[i]);
  }
  cout << ans;
  return 0;
}
