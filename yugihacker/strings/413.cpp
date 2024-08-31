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
   string ans = "";
   while (cin >> s) {
      for (char &i : s)
         i = tolower(i);
      s[0] = toupper(s[0]);
      ans += s;
      ans += " ";
   }
   for (int i = 0; i < sz(ans) - 1; ++i)
      cout << ans[i];
   return 0;
}
