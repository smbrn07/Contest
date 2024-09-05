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

int a[nmax][nmax], f[nmax][nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, q;
   cin >> n >> q;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         char ch;
         cin >> ch;
         if (ch == '*') ++a[i][j];
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
      }
   }
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = 1; j <= n; ++j) {
   //       cout << f[i][j] << " ";
   //    }
   //    cout << endl;
   // }
   while (q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1]
           << endl;
   }
   return 0;
}
