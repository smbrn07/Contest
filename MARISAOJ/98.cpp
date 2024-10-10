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

int a[nmax], b[nmax], f[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= m; ++i)
    cin >> b[i];
  int l = 1, r = 1;
  int ans = 0;
  while (r <= n) {
    ++f[a[r]];
    while (f[a[r]] > b[a[r]]) {
      --f[a[l]];
      ++l;
    }
    ans = max(ans, r - l + 1);
    ++r;
  }
  cout << ans << endl;
}
