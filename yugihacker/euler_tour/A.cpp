#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl '\n'
#define pb push_back
const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, q, pos[nmax], cnt, a[nmax], sz[nmax];
ll t[4*nmax];
vector<int> adj[nmax], v[nmax];

void dfs(int u, int p) {
	pos[u]=++cnt;
	sz[u]=1;
	for (int v : adj[u]) {
		if (v!=p) {
			dfs(v, u);
			sz[u]+=sz[v];
		}
	}
}

void update(int v, int l, int r, int pos, int val) {
	if (l==r) {
		t[v]=val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) update(2*v, l, mid, pos, val);
	else update(2*v+1, mid+1, r, pos, val);
	t[v]=t[v*2]+t[v*2+1];
}

ll query(int v, int tl, int tr, int l, int r) {
	if (r < tl || tr < l) return 0;
	if (l <= tl && tr <= r) return t[v];
	int mid = (tl+tr)/2;
	return query(2*v, tl, mid, l, r) + query(2*v+1, mid+1, tr, l, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
  	int x, y; cin >> x >> y;
  	adj[x].pb(y), adj[y].pb(x);
  }
  dfs(1, -1);
  for (int u=1; u<=n; u++)
  	update(1, 1, n, pos[u], a[u]);
  while (q--) {
  	int type, u, x;
  	cin >> type >> u;
  	if (type==1) {
  		cin >> x;
  		a[u]=x;
  		update(1, 1, n, pos[u], a[u]);
  	} else {
  		cout << query(1, 1, n, pos[u],pos[u]+sz[u]-1) << '\n';
  	}
  }
  return 0;
}