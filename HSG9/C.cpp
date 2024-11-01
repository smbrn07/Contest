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

int n, l[nmax], r[nmax], c[nmax], dp[nmax];
pair<pair<int, int>, int> a[nmax];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.ff.ss == b.ff.ss) {
    if (a.ff.ff == b.ff.ff)
      return a.ss < b.ss;
    return a.ff.ff < b.ff.ff;
  }
  return a.ff.ss < b.ff.ss;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].ff.ff >> a[i].ff.ss >> a[i].ss;
  }
  int ans = 0;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    l[i] = a[i].ff.ff, r[i] = a[i].ff.ss, c[i] = a[i].ss;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (r[j] <= l[i])
        dp[r[i]] = max(dp[r[i]], dp[r[j]] + c[i]);
      ans = max(ans, dp[r[i]]);
    }
  }
  cout << ans << endl;
  return 0;
}
