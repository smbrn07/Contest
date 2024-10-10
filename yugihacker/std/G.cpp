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
   int n;
   cin >> n;
   map<int, vector<int>> mp;
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      mp[x].pb(i);
   }
   for (auto i : mp) {
      cout << i.ff << endl;
      for (int j : i.ss) {
         cout << j << " ";
      }
      cout << endl;
   }

   return 0;
}
