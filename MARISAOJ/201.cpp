#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, q;
ll t[4*nmax], lazy[4*nmax];

void lazyupdate(int v, int val) {
	lazy[v]-=val;
}

void update(int v, int l, int r, int pos, int val) {
	if (l==r) {
		t[v]+=val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) update(2*v, l, mid, pos, val);
	else update(2*v+1, mid+1, r, pos, val);
	t[v]=min(t[2*v],t[2*v+1]);
}

ll get(int v, int tl, int tr, int l, int r) {
	if (tl>r || tr < l) return 2e9+7;
	if (tl>=l && tr<=r) return t[v];
	int mid = (tl+tr)/2;
	return min(get(2*v, tl, mid, l, r), get(2*v+1, mid+1, tr, l, r));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
  	int x; cin >> x;
  	update(1, 1, n, i, x);
  }
  while (q--) {
  	int type;
  	cin >> type;
  	if (type==1) {
  		int i, x; cin >> i >> x;
  		update(1, 1, n, i, x);
  	} else {
  		int l, r; cin >> l >> r;
  		cout << get(1, 1, n, l, r) << endl;
  	}
  }
  return 0;
}