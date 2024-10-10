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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x, y;
  cin >> x >> y;
  ll v = x * y;
  int ans = 0;
  for (ll i = 1; i * i <= v; ++i) {
    if (v % i == 0) {
      ll j = v / i;
      if (gcd(i, j) == x && lcm(i, j) == y) {
        ++ans;
        if (i != j)
          ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
