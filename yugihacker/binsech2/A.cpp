#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define endl '\n'

ll a, b, n;

bool ok(ll x) {
  ll k = a * b / gcd(a, b);
  ll cnt = x / a + x / b - x / k;
  return cnt >= n;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> a >> b >> n;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
      ll mid = l + (r - l) / 2;
      if (ok(mid))
        r = mid;
      else
        l = mid;
    }
    cout << r << endl;
  }
  return 0;
}
