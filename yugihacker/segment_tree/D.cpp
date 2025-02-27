#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, q, a[nmax];

struct node {
	ll sum, pref, suff, max_val;
} t[4*nmax];

node merge(node x, node y) {
	node v;
	v.sum = x.sum + y.sum;
	v.pref = max(x.pref, x.sum+y.pref);
	v.suff = max(y.suff, y.sum+x.suff);
	v.max_val=max({x.max_val, y.max_val, x.suff+y.pref});
	return v;
}

void update(int v, int l, int r, int pos, int val) {
	if (pos<l || r<pos) return;
	if (l==r) {
		t[v]={val, max(0,val), max(0,val), max(0,val)};
		return;
	}
	int mid = (l+r)/2;
	update(2*v, l, mid, pos, val);
	update(2*v+1, mid+1, r, pos, val);
	t[v]=merge(t[2*v], t[2*v+1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	update(1, 1, n, i, a[i]);
  }
  while (q--) {
  	int pos, val; cin >> pos >> val;
  	update(1, 1, n, pos, val);
  	cout << t[1].max_val << '\n';
  }
  return 0;
}