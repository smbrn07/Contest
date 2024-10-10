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
int n;
ll a[nmax];

ll ok(ll mid) { return mid - (lower_bound(a, a + n, mid) - a); }

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> n >> tt;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  while (tt--) {
    ll x;
    cin >> x;
    ll l = 0, r = 2e18;
    while (r - l > 1ll) {
      ll mid = l + (r - l) / 2;
      if (ok(mid) <= x)
        l = mid;
      else
        r = mid;
    }
    cout << l << endl;
  }
  return 0;
}
