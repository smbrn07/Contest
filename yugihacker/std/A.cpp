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
   vector<int> v;
   int tt;
   cin >> tt;
   while (tt--) {
      string s;
      cin >> s;
      if (s == "push") {
         int x;
         cin >> x;
         v.pb(x);
      } else if (s == "pop" && sz(v) > 0)
         v.pop_back();
      else if (s == "size")
         cout << sz(v) << endl;
      else if (s == "index") {
         int x;
         cin >> x;
         if (sz(v) >= x) {
            cout << v[x - 1] << endl;
         } else
            cout << -1 << endl;
      }
   }
   return 0;
}
