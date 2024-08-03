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

ll binpow(ll a, ll b) {
	if (b==0) return 1;
	ll res = binpow(a, b/2) % mod;
	res = (res*res)%mod;
	if (b&1) res = res*a%mod;
	return res;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int tt; cin >> tt;
   while (tt--) {
   	ll l, r, k;
   	cin >> l >> r >> k;
   	ll eps = 1+9/k;
   	ll ans = (binpow(eps, r) - binpow(eps, l))%mod;
   	if (ans < 0) ans+=mod;
   	cout << ans << endl;
   }
   return 0;
}