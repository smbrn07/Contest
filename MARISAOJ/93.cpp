#include "bits/stdc++.h"

using namespace std;


#define int int64_t
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 5e3+7;

int a[nmax], b[nmax];
vector<int> ans;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int n, x; cin >> n >> x;
   for (int i = 1; i <= n; ++i) { cin >> a[i]; b[i]=a[i]; }
   sort(a+1, a+n+1);
	bool flag=1;
	for (int i = 2; i < n; ++i) {
		if (flag==0) break;
		int l = 1, r = n;
		while (l<=r) {
			if (a[l]+a[r]+a[i]==x) {
				ans.pb(l);
				ans.pb(i);
				ans.pb(r);
				flag = 0;
				break;
			}
			if (a[l]+a[r]+a[i]<x) ++l;
			else if (a[l]+a[r]+a[i]>x) --r;
		}
	}
	// cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	int pos1, pos2, pos3;
	for (int i = 1; i <= n; ++i) {
		if (b[i]==a[ans[0]]) pos1=i;
		if (b[i]==a[ans[1]]) pos2=i;
		if (b[i]==a[ans[2]]) pos3=i;
	}
	cout << pos1 << ' ' << pos2 << ' ' << pos3 << endl;
   return 0;
}