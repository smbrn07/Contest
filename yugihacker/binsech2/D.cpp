#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define endl '\n'
const int nmax = 2e5 + 7;

ll t, n, m, a[nmax], b[nmax];

bool ok(ll mid) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += mid / a[i];
  for (int i = 0; i < m; ++i)
    cnt -= (t - mid) / b[i];
  return cnt <= 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> b[i];
  ll l = 0, r = t;
  while (r - l > 1) {
    ll mid = l + (r - l) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += l / a[i];
  cout << ans << endl;
  return 0;
}
