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

int n, l[nmax], r[nmax], dp[nmax];
pair<int, int> a[nmax];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.ss == b.ss)
    return a.ff < b.ff;
  return a.ss < b.ss;
}

void updt(int l, int r) {
  for (int i = l; i <= r; ++i) {
    dp[i] = dp[i - 1];
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].ff >> a[i].ss;
  }
  int ans = 0;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    l[i] = a[i].ff, r[i] = a[i].ss;
  }
  for (int i = 1; i <= n; ++i) {
    updt(r[i - 1] + 1, r[i]);
    dp[r[i]] = max(dp[r[i]], dp[l[i] - 1] + r[i] - l[i] + 1);
    ans = max(ans, dp[r[i]]);
  }
  cout << ans << endl;

  return 0;
}
