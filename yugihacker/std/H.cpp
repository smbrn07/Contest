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

ll sumi[nmax], sumj[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, m, q;
   cin >> n >> m >> q;
   vector<vector<int>> a(n + 7, vector<int>(m + 7));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cin >> a[i][j];
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         sumi[i] += a[i][j];
      }
   }
   for (int j = 1; j <= m; ++j) {
      for (int i = 1; i <= n; ++i) {
         sumj[j] += a[i][j];
      }
   }
   while (q--) {
      char s;
      cin >> s;
      if (s == '1') {
         int i, j;
         cin >> i >> j;
         swap(a[i], a[j]);
         swap(sumi[i], sumi[j]);
      } else if (s == '2') {
         int i, j, x;
         cin >> i >> j >> x;
         sumi[i] += -a[i][j] + x;
         sumj[j] += -a[i][j] + x;
         a[i][j] = x;
      } else if (s == 'r') {
         int i;
         cin >> i;
         cout << sumi[i] << endl;
      } else if (s == 'c') {
         int i;
         cin >> i;
         cout << sumj[i] << endl;
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
