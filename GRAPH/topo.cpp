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
vector<int> topo;
void dfs(int u) {
	visited[u]=1;
	for (int v : adj[u]) {
		if (!visited[v]) {
			visited[v]=1;
			dfs(v);
		}
		topo.pb(v);
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y); adj[y].pb(x);
   }
   
   return 0;
}