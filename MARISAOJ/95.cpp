#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define int int64_t
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 1e5+7;

int a[nmax];
int f[nmax], fi[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int n, k; cin >> n >> k;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   sort(a+1, a+n+1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int pos = lower_bound(a+1, a+i+1, a[i]-k)-a;
		f[i]=i-pos+1;
		fi[i]=max(f[i], fi[i-1]);
		// cout << f[i] << endl;		
	}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, fi[i-f[i]]+f[i]);
	}
	cout << ans << endl;
   return 0;
}