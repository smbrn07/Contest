#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, q, a[nmax], t[4*nmax];

void mkt(int v, int l, int r) {
	if (l==r) t[v]=a[l];
	else {
		int mid = (l+r)/2;
		mkt(2*v, l, mid), mkt(2*v+1, mid+1, r);
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tl==tr) if (tr<=r && tl>=l) t[v]+=val;
	else {
		int mid = (tl+tr)/2;
		update(2*v, tl, mid, l, r, val), update(2*v+1, mid+1, tr, l, r, val);
		t[v]=min(t[2*v], t[2*v+1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l>r) return 2e9;
	if (tl==l && tr==r) return t[v];
	else {
		int tmid = (tl+tr)/2;
		int min1 = query(2*v, tl, tmid, l, min(r, tmid));
		int min2 = query(2*v+1, tmid, tr, max(tmid, l), r);
		return min(min1, min2);
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  while (q--) {
  	int x; cin >> x;
  	if (x==1) {
  		int l, r, val; cin >> l >> r >> val;
  		update(1, 1, n, l, r, val);
  	} else {
  		int l, r; cout << query(1, 1, n, l, r) << '\n';
  	}
  }
  return 0;
}