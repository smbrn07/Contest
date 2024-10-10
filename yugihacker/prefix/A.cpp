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

ll f[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      f[i] = f[i - 1] + x;
   }
   int tt;
   cin >> tt;
   while (tt--) {
      int l, r;
      cin >> l >> r;
      cout << f[r] - f[l - 1] << endl;
   }

   return 0;
}
