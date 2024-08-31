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
   cin >> n >> m;
   set<set<int>> s;
   for (int i = 1; i <= n; ++i) {
      set<int> v;
      for (int j = 0; j < m; ++j) {
         int x;
         cin >> x;
         v.insert(x);
      }
      s.insert(v);
   }
   cout << sz(s) << endl;
   return 0;
}
