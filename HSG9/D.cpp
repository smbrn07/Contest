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
const int nmax = 1e6 + 7;

int n;
double v, b[nmax], w[nmax], h[nmax], d[nmax];
int tt;

bool ok(double mid) {
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (mid >= b[i]) {
      ans += w[i] * d[i] * min(h[i], mid - b[i]);
    }
  }
  return ans <= v;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> v;
  double maxval = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i] >> h[i] >> w[i] >> d[i];
    maxval = max(maxval, h[i] + b[i]);
  }
  double l = 0, r = maxval, eps = 1e-4;
  cin >> tt;
  while (r - l > eps) {
    double mid = l + (r - l) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  cout << setprecision(2) << fixed << l << endl;
  return 0;
}
