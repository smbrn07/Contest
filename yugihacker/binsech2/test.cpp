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
const int nmax = 2e5 + 7;

ll n, m;
ll a[nmax];

bool ok(ll x) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += min(x / a[i], (ll)1e9);
  }
  return cnt >= m;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  ll l = 0, r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid;
    } else
      l = mid;
  }
  cout << r << endl;
  return 0;
}
 
