#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, q;
ll lazy[4*nmax], t[4*nmax];

void push(int v) {
	if (lazy[v]!=0) {
		t[2*v]+=lazy[v];
		t[2*v+1]+=lazy[v];
		lazy[2*v]+=lazy[v];
		lazy[2*v+1]+=lazy[v];
		lazy[v]=0;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (r < tl || tr < l) return;
	if (l<=tl && tr<=r) {
		t[v]+=val;
		lazy[v]+=val;
		return;
	}
	int mid = (tl+tr)/2;
	push(v);
	update(2*v, tl, mid, l, r, val);
	update(2*v+1, mid+1, tr, l, r, val);
	t[v]=min(t[2*v], t[2*v+1]);
}

ll query(int v, int tl, int tr, int l, int r) {
	if (r < tl || tr < l) return 1e15;
	if (l <= tl && tr <= r) return t[v];
	int mid = (tl+tr)/2;
	push(v);
	return min(query(2*v, tl, mid, l, r), query(2*v+1, mid+1, tr, l, r));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
  	int x; cin >> x;
  	update(1, 1, n, i, i, x);
  }
	while (q--) {
		int type, l, r, x;
		cin >> type >> l >> r;
		if (type==1) {
			cin >> x;
			update(1, 1, n, l, r, x);
		} else {
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
  return 0;
}