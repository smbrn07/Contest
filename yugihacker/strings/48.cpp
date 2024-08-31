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
   string s, t;
   cin >> s >> t;
   int lens = sz(s), lent = sz(t);
   ll cnt = 0;
   for (int i = 0; i <= lens - lent; ++i) {
      string cur = s.substr(i, lent);
      if (cur == t)
         ++cnt;
   }
   cout << cnt << endl;
   return 0;
}
