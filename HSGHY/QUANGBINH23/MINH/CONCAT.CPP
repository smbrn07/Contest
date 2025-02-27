#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, tt, b[nmax];
ll a[nmax], L, R;

int cnt(ll x) {
	for (ll i = 10; i <= 1e15; i*=10) {
		if (x/i == 0) return i;
	}
	return 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
	cin >> n >> L >> R;
  	for (int i = 1; i <= n; ++i) cin >> a[i];
  	sort(a+1, a+n+1);
  	ll ans = 0;
  	for (int i = 1; i <= n; ++i) {
  		int low=max(a[i], L/cnt(a[i]));
  	}
  }
  return 0;
}