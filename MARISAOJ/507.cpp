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
ll a[nmax], b[nmax], c[nmax];
ll ans = 1e12 + 7;

void np(ll d[]) {
  for (int i = 0; i < n; ++i)
    cin >> d[i];
}

void cal(ll x[], ll y[], ll z[]) {
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    while (l + 1 < n && y[l + 1] <= x[i]) {
      ++l;
    }
    while (r + 1 < n && z[r + 1] <= x[i]) {
      ++r;
    }
    if (x[i] >= max(y[l], z[r]))
      ans = min(ans, 2 * (x[i] - min(y[l], z[r])));
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  np(a), np(b), np(c);
  sort(a, a + n), sort(b, b + n), sort(c, c + n);
  cal(a, b, c);
  // cal(b, a, c);
  // cal(c, a, b);
  cout << ans << endl;

  return 0;
}
