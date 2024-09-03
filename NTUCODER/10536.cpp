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

int n, k, h;
int a[nmax];

signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> k >> h;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   int num = 1 + 2 * h / k;
   ll cur = 0;
   for (int i = 1; i <= num; ++i) cur += a[i];
   ll ans = cur;
   for (int i = 1; i <= n; ++i) {
      ans = max(ans, cur);
      cur = cur - a[i] + a[i + num];
   }
   cout << ans << endl;

   return 0;
}
