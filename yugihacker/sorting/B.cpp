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
const int nmax = 1e6 + 7;

pair<int, int> a[nmax];

bool cmp(pair<int, int> a, pair<int, int> b) {
   return a.ff - a.ss < b.ff - b.ss;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   n *= 2;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i].ff >> a[i].ss;
   }
   sort(a + 1, a + n + 1, cmp);
   ll ans = 0;
   for (int i = 1; i <= n / 2; ++i) {
      ans += a[i].ff;
   }
   for (int i = 1 + n / 2; i <= n; ++i) {
      ans += a[i].ss;
   }
   cout << ans << endl;
   return 0;
}
