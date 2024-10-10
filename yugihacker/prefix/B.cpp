#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 2e9 + 7;
const int nmax = 2e6 + 7;

ll f[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, k;
   cin >> n >> k;
   for (int i = 1; i <= n; ++i) {
      ll x;
      cin >> x;
      f[i] = f[i - 1] + x;
   }
   ll ans = f[k] - f[0];
   for (int i = k; i <= n; ++i) {
      ans = max(ans, f[i] - f[i - k]);
   }
   cout << ans << endl;
   return 0;
}
