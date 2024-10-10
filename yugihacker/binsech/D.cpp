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

int t, n, m, a[nmax], b[nmax];
ll cnt1, cnt2;

bool ok(int mid) {
  cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    cnt1 += mid / a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cnt2 += (t - mid) / b[i];
  }
  return cnt2 >= cnt1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; ++i)
    cin >> b[i];
  int l = -1, r = t + 1;
  ll ans = 0;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (ok(mid)) {
      ans = max(ans, cnt1);
      l = mid;
    } else
      r = mid;
  }
  cout << ans << endl;
  return 0;
}
