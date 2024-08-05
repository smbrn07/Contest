#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 1e5+7;

int n, m;
vector<int> adj[nmax];
bool visited[nmax];
bool color[nmax];

void dfs(int u) {
	visited[u]=1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			color[v]=!color[u];
			visited[v]=1;
			dfs(v);
		}
	}
}

void connectedcomponent() {
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y);
   	adj[y].pb(x);
   }
   connectedcomponent();
   bool flag = 1;
   for (int i = 1; i <= n; ++i) {
   	for (int j : adj[i]) if (color[j]==color[i]) flag = 0;
   }
	cout << (flag ? "YES" : "NO") << endl;
   return 0;
}
   