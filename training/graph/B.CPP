#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, m, cnt, d[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void bfs(int x) {
	queue<int> pq;
	pq.push(x);
	while (!pq.empty()) {
		int u = pq.front(); pq.pop();
		for (int v = 0; v < adj[u].size(); ++v) {
			if (!visited[adj[u][v]]) {
				d[adj[u][v]]=d[u]+1;
				visited[adj[u][v]]=1;
				pq.push(adj[u][v]);
			}
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
  	int x, y; cin >> x >> y;
  	adj[x].pb(y); adj[y].pb(x);
  }
  d[1]=1;
  for (int i = 2; i <= n; ++i) d[i]=-1e9;
  bfs(1);
  cout << (d[n]!=-1e9?d[n]:-1);
  return 0;
}