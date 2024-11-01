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

int n, q, s, t, l, r, x, d[nmax], tmp, cur;
ll neg = 0, pos = 0;

void upd(int b, bool f) { (d[b] < 0 ? neg : pos) -= d[b] * (f ? 1 : -1); }

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s >> t;
  for (int i = 0; i <= n; ++i) {
    cin >> cur;
    if (i)
      d[i] = tmp - cur;
    (d[i] < 0 ? neg : pos) += d[i];
    tmp = cur;
  }
  while (q--) {
    cin >> l >> r >> x;
    upd(l, 1), upd(r + 1, 1);
    d[l] -= x, d[r + 1] += x;
    d[r + 1] = (r + 1 > n ? 0 : d[r + 1]);
    upd(l, 0), upd(r + 1, 0);
    cout << s * neg + t * pos << endl;
  }
  return 0;
}
