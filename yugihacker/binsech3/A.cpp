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
  cin >> n >> tt;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  while (tt--) {
    int t, x;
    cin >> t >> x;
    if (t == 1)
      cout << (binary_search(a, a + n, x) ? "YES" : "-1") << endl;
    else {
      bool flag = binary_search(a, a + n, x);
      if (t == 2) {
        int pos = lower_bound(a, a + n, x) - a;
        cout << ((flag && a[pos] == x) ? pos + 1 : -1) << endl;
      } else {
        int pos = upper_bound(a, a + n, x) - a - 1;
        cout << ((flag && a[pos] == x) ? pos + 1 : -1) << endl;
      }
    }
  }

  return 0;
}
