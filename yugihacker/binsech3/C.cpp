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

int n, a[nmax], q;

int tk2(int x) {
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= x) {
      l = mid;
    } else
      r = mid;
  }
  if (l >= 0 && l < n)
    return l;
  return -1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int pos1 = lower_bound(a, a + n, l) - a;
    int pos2 = tk2(r);
    if (pos1 != n && pos2 != -1 && a[pos1] <= r && a[pos2] >= l && l <= r)
      cout << pos2 - pos1 + 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
