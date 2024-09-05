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

vector<int> ch;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   for (int i = 1; i <= 10; ++i) {
      int x;
      cin >> x;
      ch.pb(x);
   }
   int tt;
   cin >> tt;
   ll ans = 0;
   while (tt--) {
      string s;
      cin >> s;
      for (char i : s) {
         ans += ch[i - '0'];
      }
   }
   cout << ans << endl;
   return 0;
}
