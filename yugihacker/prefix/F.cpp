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
const int nmax = 1e3 + 7;

ll a[nmax][nmax];

// TRUY VAN CAP NHAT DOAN MANG 2 CHIEU:
// a[x1][y1]++;
// a[x2+1][y1]++;
// a[x1][y2+1]++;
// a[x2+1][y2+1]++;
// CAP NHAT LAI MANG
// a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   int q;
   cin >> q;
   while (q--) {
      int x1, y1, x2, y2, x;
      cin >> x1 >> y1 >> x2 >> y2 >> x;
      a[x1][y1] += x;
      a[x2 + 1][y2 + 1] += x;
      a[x1][y2 + 1] -= x;
      a[x2 + 1][y1] -= x;
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cout << a[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}
