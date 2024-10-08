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

bool ok(ll n) {
  if (1ll * sqrt(n) * sqrt(n) == n)
    return 1;
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
      ll x;
      cin >> x;
      sum += x;
    }
    cout << (ok(sum) ? "YES" : "NO") << endl;
  }
  return 0;
}
