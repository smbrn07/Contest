#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, k, m, d[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v = 0; v < adj[u].size(); ++v) {
			if (!visited[adj[u][v]]) {
				visited[adj[u][v]]=1;
				q.push(adj[u][v]);
				d[adj[u][v]]=d[u]+1;
			}
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
  	int x; cin >> x;
  	adj[0].pb(x); adj[x].pb(0);
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
  	int x, y; cin >> x >> y;
  	adj[x].pb(y); adj[y].pb(x);
  }
  bfs(0);
  for (int i = 1; i <= n; ++i) cout << d[i]-1 << ' ';
  return 0;
}