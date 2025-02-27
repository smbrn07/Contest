#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e7 + 7;

int n, m, a[nmax], f[nmax];

bool check() {
	for (int i = 1; i <= m; ++i) if (f[i]<1) return 1;
	return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
    if (n==m) {
 	cout << n << endl;
 	return 0;
  }
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	++f[a[i]];
  }
  if (check()) {
  	cout << 0;
  	return 0;
  }
  int l = 1, r = n;
  for (int i = n; i >= 1; --i) {
  	if (f[a[i]]>1) --f[a[i]];
  	else {
  		r = i;
  		break;
  	}
  }
  int ans = n;
  while (r<=n) {
  	while (f[a[l]]>1) {
  		--f[a[l]];
  		++l;
  	}
  	ans=min(ans, r-l+1);
  	++r;
  	++f[a[r]];
  }
  cout << ans << endl;
  return 0;
}