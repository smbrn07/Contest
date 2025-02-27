#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, a[nmax], b[nmax], dp[nmax], t[4*nmax];

int get(int v, int tl, int tr, int l, int r) {
	if (tl>r || tr<l) return 0;
	if (tl>=l && tr<=r) return t[v];
	int mid = (tl+tr)/2;
	return max(get(2*v, tl, mid, l, r), get(2*v+1, mid+1, tr, l, r));
}

void update(int v, int l, int r, int pos, int val) {
	if (l==r)  {
		t[v]=val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) update(2*v, l, mid, pos, val);
	else update(2*v+1, mid+1, r, pos, val);
	t[v]=max(t[2*v], t[2*v+1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	b[i]=a[i];
  }
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
  	a[i]=lower_bound(b+1, b+n+1, a[i])-b;
  }
  // for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  for (int i = 1; i <= n; ++i) {
  	dp[a[i]]=get(1, 1, n, 1, a[i]-1)+1;
  	update(1, 1, n, a[i], dp[a[i]]);
  }
  cout << get(1, 1, n, 1, n);
  return 0;
}