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
const int nmax = (1 << 20) + 10;

int n, a[nmax];

ll calc(int i) {
   if (i == 0) return 0;
   map<int, int> mp;
   ll res = 0, cnt = 0;
   for (int l = 1, r = 1; r <= n; ++r) {
      cnt += (++mp[a[r]] == 1);
      while (l < r && cnt > i) {
         cnt -= (--mp[a[l++]] == 0);
      }
      res += r - l + 1;
   }
   return res;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int l, u;
   cin >> n >> l >> u;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   cout << calc(u) - calc(l - 1) << endl;
   // cout << f(u) - f(l - 1) << endl;

   return 0;
}
