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

ll a[nmax], b[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   int q;
   cin >> q;
   while (q--) {
      int l, r, x;
      cin >> l >> r >> x;
      b[l] += x;
      b[r + 1] -= x;
   }
   for (int i = 1; i <= n; ++i) {
      b[i] += b[i - 1];
   }
   for (int i = 1; i <= n; ++i) {
      cout << a[i] + b[i] << " ";
   }

   return 0;
}
