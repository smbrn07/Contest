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

int a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, tt;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int u1 = lower_bound(a + 1, a + n + 1, l) - a;
    int u2 = upper_bound(a + 1, a + n + 1, r) - a;
    cout << u2 - u1 << endl;
  }
}
