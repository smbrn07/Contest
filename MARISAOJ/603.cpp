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

int n, q, s, t;
ll a[nmax], d[nmax], neg = 0, pos = 0;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s >> t;
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
    if (i)
      d[i] = a[i - 1] - a[i];
    (d[i] < 0 ? neg : pos) += d[i];
  }
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    // d[r + 1] = (r + 1 > n ? 0 : d[r + 1]);
    (d[l] < 0 ? neg : pos) -= d[l];
    (d[r + 1] < 0 ? neg : pos) -= d[r + 1];
    d[l] -= x;
    d[r + 1] += x;
    d[r + 1] = (r + 1 > n ? 0 : d[r + 1]);
    (d[l] < 0 ? neg : pos) += d[l];
    (d[r + 1] < 0 ? neg : pos) += d[r + 1];
    cout << s * neg + t * pos << endl;
  }

  return 0;
}
