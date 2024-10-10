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

int n, k;
int a[nmax];

bool ok(int x) {
  ll cnt = 0;
  for (int i = (n - 1) / 2; i < n; ++i) {
    cnt += max(0, x - a[i]);
  }
  return cnt <= k;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  ll l = -1e9 - 7, r = 1e9 + 7;
  int ans = -2e9 - 7;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
