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
const int nmax = 406;

ll a[nmax][nmax];
ll pref1[500][500], pref2[500][500];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         cin >> a[i][j];
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         pref1[i][j] = pref1[i - 1][j + 1] + a[i][j];
         pref2[i][j] = pref2[i - 1][j - 1] + a[i][j];
      }
   }
   ll ans = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
         int d = i - j + 1;
         for (int k = d; k <= n; ++k) {
            int l = k - i + j;
            ll cur = pref2[i][k] - pref2[j - 1][l - 1] - pref1[i][l] +
                     pref1[j - 1][k + 1];
            ans = max(ans, cur);
         }
      }
   }
   cout << ans << endl;
   return 0;
}
