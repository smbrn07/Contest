#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define allin(v) begin(v), end(v)
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name)                                                             \
  if (fopen(name ".in", "r")) {                                                \
    freopen(name ".in", "r", stdin);                                           \
    freopen(name ".out", "w", stdout);                                         \
  }

const int nmax = 1e5 + 7;
double v[nmax], w[nmax];
pair<int, double> c[nmax];
int n, k;
vector<int> kq;
bool cmp(pair<int, double> x, pair<int, double> y) { return x.ss > y.ss; }
bool check(double mid) {
  kq.clear();
  double s = 0;
  for (int i = 1; i <= n; ++i) {
    c[i] = {i, v[i] - mid * w[i]};
  }
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= k; ++i) {
    kq.pb(c[i].ff);
    s += c[i].ss;
  }
  return s > 0;
}

signed main() {
  fastIO;
  cin >> n >> k;
  double r = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
    r = max({r, v[i], w[i]});
  }
  double l = 0, eps = 1e-4;
  while (r - l > eps) {
    double mid = l + (r - l) / 2;
    if (check(mid)) {
      l = mid;
    } else
      r = mid;
  }
  ll ab = 0, ba = 0;
  for (int i : kq) {
    ab += v[i];
    ba += w[i];
  }
  ll uc = gcd(ab, ba);
  cout << ab / uc << " " << ba / uc << endl;

  return 0;
}
