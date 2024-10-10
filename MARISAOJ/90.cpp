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
double a[nmax], b[nmax], pref[nmax], pref_min;

bool ok(double mid) {
  pref_min = 0;
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i] - mid;
    pref[i] = pref[i - 1] + b[i];
  }
  for (int i = k; i <= n; ++i) {
    pref_min = min(pref_min, pref[i - k]);
    if (pref[i] - pref_min >= 0)
      return 1;
  }
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  double l = 0, r = 1e9, eps = 1e-4;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  cout << fixed << setprecision(3) << l << endl;
  return 0;
}
