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
   int n, q, k;
   cin >> n >> q >> k;
   vector<int> pos;
   int cnt = 0;
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if (x == q) {
         ++cnt;
         pos.pb(i);
      }
   }
   if (cnt == 0)
      cout << -1 << endl;
   else {
      cout << cnt << endl;
      for (int i : pos) cout << i << " ";
   }

   return 0;
}
