#include "bits/stdc++.h"

using namespace std;

typedef int64_t ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 1e5+7;

const ll maxv = 162;
ll n;

bool check(ll x, ll f) {
	ll sum = 0;
	while (x>0) {
		sum+=x%10;
		x/=10;
	}
	return sum==f;
}

ll proc(ll f) {
	ll del = f*f + 4*n;
	if (del<0) return -1;
	ll sqdel = sqrtl(del);
	if (sqdel*sqdel!=del) return -1;

	ll x = - f + sqdel;
	if (x&1) return -1;
	return x/2;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n;
   ll res=1e18;
   bool flag=1;
   for (ll i = 0; i <= maxv; ++i) {
   	ll ans = proc(i);
   	if (ans >= 0 && check(ans, i)) { flag=0; res=min(res, ans); }
   }
   if (!flag) cout << res << endl;
   else cout << -1 << endl;
   // cout << check(1, 1);
   return 0;
}