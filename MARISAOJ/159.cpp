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
const int nmax = 1e3 + 7;

ll a[nmax], f[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   ll n, k; cin >> n >> k;
   f[0]=1;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   	
   for (int i = 1; i <= n; ++i) {
   	for (int j = i; j >= 1; --j) {
   		f[j] += (f[j-1]%mod) * (a[i]%mod);
   		f[j]%=mod;
   	}
   }
   cout << f[k] << endl;
   return 0;
}