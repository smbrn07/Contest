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
   map<int, int> mp;
   int tt;
   cin >> tt;
   int cnt = 0;
   while (tt--) {
      string s;
      cin >> s;
      if (s == "add") {
         int x;
         cin >> x;
         ++mp[x];
         if (mp[x] == 1)
            ++cnt;
      } else if (s == "del") {
         int x;
         cin >> x;
         if (mp[x] > 0) {
            --mp[x];
            if (mp[x] == 0)
               --cnt;
         }
      } else if (s == "count") {
         int x;
         cin >> x;
         cout << mp[x] << endl;
      } else {
         cout << cnt << endl;
      }
   }

   return 0;
}
