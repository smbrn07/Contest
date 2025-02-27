#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, k;
ll a[nmax];

ll ok(ll x) {
	ll cur = 0, cnt = 0;
	for (int i = 1; i <= n+1; ++i) {
		if (cur+a[i]<=x) cur+=a[i];
		else {
			cur=a[i];
			++cnt;
		}
	}
	return cnt<=k;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  ll l = 0, r = 1e18+7;
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	l = max(l, a[i]);
  }
	ll ans = 0;
	a[n+1]=1e18+7;
	while (l<=r) {
		ll mid = (l+r)/2;
		if (ok(mid)) {
			ans = mid;
			r = mid-1;
		} else l = mid+1;
	}
	cout << ans << endl;
  return 0;
}