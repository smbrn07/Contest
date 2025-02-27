#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll n, k, a[nmax];
double b[nmax], minval[nmax];

bool ok(double mid) {
	for (int i = 1; i <= n; ++i) b[i]=a[i]-mid;
	double cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur+=b[i];
		if (i-k>=0 && cur-minval[i-k]>=0) return 1;
		minval[i]=min(minval[i-1], cur);
	}
	return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  double l = 0, r = 1e12, eps = 1e-4, res = 1;
	while (r-l>eps) {
		double mid = (r-l)/2+l;
		if (ok(mid)) {
			res = mid;
			l = mid;
		} else r = mid;
	}
	cout << fixed << setprecision(6) << res;
	return 0;
}