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

int n, m, f[nmax];
vector<pair<int, int>> p;

bool check() {
  for (int i = 1; i <= n; ++i)
    if (f[i] == 0)
      return 0;
  return 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      p.pb({x, i});
    }
  }
  sort(allin(p));
  int ans = 1e9;
  for (int l = 0, r = 0; r < n * m; ++r) {
    ++f[p[r].ss];
    if (check()) {
      while (f[p[l].ss] > 1) {
        --f[p[l].ss];
        ++l;
      }
      ans = min(ans, p[r].ff - p[l].ff);
    }
  }
  cout << ans << endl;
  return 0;
}
