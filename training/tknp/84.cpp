#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll ok(ll x) {
	return x/3+x/5+x/7-x/21-x/35-x/15+x/105;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll k; cin >> k;
  ll l = 1, r = 1e18+7, ans;
  while (l<=r) {
  	ll mid = (l+r)/2;
  	if (ok(mid)>=k) {
  		ans = mid;
  		r = mid-1;
  	} else l = mid+1;
  }
  cout << ans << endl;
  return 0;
}