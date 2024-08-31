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
   string s;
   cin >> s;
   int len = sz(s);
   ll cnt = len;
   for (int i = 0; i < len; ++i) {
      int l = i - 1, r = i + 1;
      while (l >= 0 && r < len && s[l] == s[r]) {
         ++cnt;
         --l;
         ++r;
      }
   }
   for (int i = 1; i < len; ++i) {
      if (s[i] == s[i - 1]) {
         ++cnt;
         int l = i - 2, r = i + 1;
         while (l >= 0 && r < len && s[l] == s[r]) {
            ++cnt;
            --l;
            ++r;
         }
      }
   }
   cout << cnt << endl;
   return 0;
}
