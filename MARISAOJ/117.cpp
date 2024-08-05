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
int parent[nmax];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				visited[x]=1;
				q.push(x);
				parent[x]=v;				
			}
		}
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y); adj[y].pb(x);
   }
   bfs(1);
   if (!visited[n]) cout << -1 << endl;
   else {
   	vector<int> path;
   	while (n!=1) {
   		path.pb(n);
   		n=parent[n];
   	}
   	path.pb(1);
   	reverse(allin(path));
   	cout << sz(path)-1 << endl;
   	for (int i : path) cout << i << ' ';
   }
   return 0;
}