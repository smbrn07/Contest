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

ll ans = 0;

ll strint(string s) {
   reverse(allin(s));
   ll res = 0;
   while (sz(s) > 1) {
      res += s.back() - '0';
      s.pop_back();
      res *= 10;
   }
   res += s.back() - '0';
   return res;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   while (cin >> s) {
      s = s + "a";
      int len = sz(s);
      string cur = "";
      for (int i = 0; i < len; ++i) {
         if (s[i] <= '9') {
            cur.pb(s[i]);
         }
      }
      if (sz(cur) > 0)
         ans += strint(cur);
   }
   cout << ans << endl;
   return 0;
}
