#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

pair<int, int> a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // freopen("minkseq.inp", "r", stdin);
  // freopen("minkseq.out", "w", stdout);
  int tt;
  cin >> tt;
  while (tt--) {
    ll ans = 1e12;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      cin >> a[i].first;
    for (int i = 1; i <= n; ++i)
      cin >> a[i].second;
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for (int i = 1; i < k; ++i) {
      sum += a[i].second;
    }
    for (int i = k; i <= n; ++i) {
      ans = min(ans, 1ll * (sum + 1ll * a[i].second) * a[i].first);
    }
    cout << ans << '\n';
  }
}
