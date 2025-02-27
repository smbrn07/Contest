#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll n, m, k;

ll ok(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= min(n, x); ++i) {
		cnt+=min(x, m*i)/i;
	}
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    ll l=1, r=1e10+7;
    ll ans=0;
    while (l<=r) {
        ll mid=(l+r)/2;
        if (ok(mid)>=k) {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
    return 0;
}