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
const int nmax = 1e3+7;

int n, m, k;
vector<int> adj[nmax];
bool visited[nmax];
int d[nmax][nmax];
int parent[nmax];

void bfs(int u) {
	queue<int> q; q.push(u);
	visited[u]=1;
	d[u][u]=0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				parent[x]=v;
				visited[x]=1;
				d[x][v]=d[v][parent[v]]+1;
				q.push(x);
			}
		}
	}	
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m >> k;
   vector<int> tt(k);
   for (int i = 0; i < k; ++i) cin >> tt[i];
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y);
   	adj[y].pb(x);
   }
   bfs(1);
   return 0;
}