#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name)                  \
   freopen(name ".in", "r", stdin); \
   freopen(name ".out", "w", stdout);

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n;
int a[nmax];
ll pref[nmax], suff[nmax], sub[nmax], l[nmax], r[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n;
   ll prefmin = 0;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
      sub[i] = max(sub[i - 1], pref[i] - prefmin);
      prefmin = min(prefmin, pref[i]);
   }
   for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] + a[i];
   ll suffmin = 0;
   for (int i = n; i >= 1; --i) {
      r[i] = max(r[i + 1], suff[i] - suffmin);
      suffmin = min(suffmin, suff[i]);
   }

   ll submax = 0;
   for (int i = 2; i <= n; ++i) {
      l[i] = pref[i] + submax;
      submax = max(submax, -pref[i] + sub[i]);
   }
   ll ans = 0;
   for (int i = 1; i < n; ++i) {
      ans = max({ans, l[i] + r[i + 1], l[i + 1], r[i]});
   }
   cout << ans << endl;
   return 0;
}