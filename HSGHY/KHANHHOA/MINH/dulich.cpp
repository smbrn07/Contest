#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, a[nmax], b[nmax], f[nmax];
map<int, int> mp;

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
freopen("dulich.inp", "r", stdin);
freopen("dulich.out", "w", stdout);
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    v.pb(a[i]);
    v.pb(b[i]);
  }
  sort(v.begin(), v.end());
  int cur = 1;
  for (int i = 0; i < v.size(); ++i) {
    if (!mp[v[i]]) {
      mp[v[i]] = cur;
      ++cur;
    }
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = mp[a[i]];
    b[i] = mp[b[i]];
    ++f[a[i]];
    --f[b[i] + 1];
  }
  for (int i = 1; i <= n; ++i)
    f[i] += f[i - 1];
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans;
  return 0;
}
