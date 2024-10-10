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

int f[26][nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n, q;
   cin >> n >> q;
   string s;
   cin >> s;
   s = " " + s;
   for (int i = 1; i <= n; ++i) {
      ++f[s[i] - 'a'][i];
   }
   for (int i = 0; i <= 25; ++i) {
      for (int j = 1; j <= n; ++j) {
         f[i][j] = f[i][j] + f[i][j - 1];
      }
   }
   while (q--) {
      char s;
      int l, r;
      cin >> s >> l >> r;
      cout << f[s - 'a'][r] - f[s - 'a'][l - 1] << endl;
   }
   return 0;
}

