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

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, m;
   ll maxv = -1, pos = -1;
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
      ll max1 = -1, max2 = -1;
      for (int j = 1; j <= m; ++j) {
         ll x;
         cin >> x;
         if (x >= max1) {
            max2 = max1, max1 = x;
         } else if (x > max2)
            max2 = x;
      }
      ll ans = max1 * max2;
      if (ans > maxv) {
         pos = i;
         maxv = ans;
      }
   }
   cout << maxv << " " << pos << endl;

   return 0;
}
