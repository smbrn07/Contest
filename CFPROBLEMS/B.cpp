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

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int tt; cin >> tt;
   while (tt--) {
   	int n; cin >> n;
   	vector<int> a(n);
   	for (int i = 0; i < n; ++i) cin >> a[i];
   	int max0 = 0, max1 = 0;
   	for (int i = 0; i < n; ++i) {
   		if ((a[i])%2 && a[i]>max1) max1=a[i];
   		if (!(a[i])%2 && a[i]>max0) max0=a[i];
   	}
   	int ans = 0;
   	bool flag = 1;
   	for (int i = 1; i < n; ++i) {
   		if (a[i]%2 != a[0]%2) {
   			flag = 0;
   			break;
   		}
   	}
   	if (flag) { cout << 0 << endl; continue; }

   	sort(allin(a));
   	for (int i = 0; i < n; ++i) {
   		if (!(a[i]%2) && a[i]<max1) {
   			++ans;
   			a[i]=a[i]+max1;
   			max1=max(max1, a[i]);
   		}
   	}
   	flag = 1;
   	for (int i = 1; i < n; ++i) {
   		if (a[i]%2 != a[0]%2) {
   			flag = 0;
   			break;
   		}
   	}
   	if (flag) { cout << ans << endl; continue; }

   	int pos = 0;
   	for (int i = 0; i < n; ++i) {
   		if (a[i]%2 && a[i]==max1) {
   			pos = i;
   			break;
   		}
   	}
   	a[pos] = max1+max0;
   	++ans;

   	for (int i = 0; i < n; ++i) {
   		if (a[i]%2==0) ++ans;
   	}

   	cout << ans << endl;
   }
   return 0;
}