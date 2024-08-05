#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 2e5+7;

signed main() {
   int tt; cin >> tt;
   while (tt--) {
      int n, k;
      cin >> n >> k;
      vector<int> a(n);
      int maxv=a[0];
      for (int i = 0; i < n; ++i) {
      	cin >> a[i];
      	maxv=max(maxv, a[i]);
      }
      bool flag = 1;
      int ans = -1;
      for (int i = maxv; i < maxv+k; ++i) {
      	for (int j = 0; j < n; ++j) {
      		int x = (i-a[j])/k;
      		if (x%2==1 || i>=a[j]+(x+1)*k) { flag = 0; break; }
      	}
      	if (flag) ans = i;
      }
      cout << ans << endl;
   }
}