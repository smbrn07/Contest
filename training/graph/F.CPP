#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m, cnt, sz[nmax], a[nmax];
vector<int> adj[nmax], v;
bool visited[nmax];

int maxval;
ll sum;
pair<ll, int> p[nmax];

void dfs(int u) {
	visited[u]=1;
	++cnt;

	sum+=a[u];
	maxval=max(maxval, a[u]);

	v.pb(u);
	for (int v = 0; v < adj[u].size(); ++v) {
		if (!visited[adj[u][v]]) {
			dfs(adj[u][v]);
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
  	int x, y; cin >> x >> y;
  	adj[x].pb(y); adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
  	if (!visited[i]) {
  		v.clear();
  		sum = 0, maxval=0;
  		cnt=0;
  		dfs(i);
  		for (int k = 0; k < v.size(); ++k) {
  			p[v[k]] = make_pair(sum, maxval);
  			sz[v[k]]=cnt;
  		}
  	}
  }
  int tt; cin >> tt;
  while (tt--) {
  	int x; cin >> x;
	cout << sz[x] << ' ' << p[x].first << ' ' << p[x].second << endl;
}
  return 0;
}