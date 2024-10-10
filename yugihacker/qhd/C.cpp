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
const int nmax = 5e3 + 7;

int n, a[nmax], f[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    f[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[i] > a[j])
        f[i] = max(f[i], f[j] + 1);
    }
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}
