#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m;
ll cnt;
vector<int> adj[nmax];
bool visited[nmax];

void dfs(int u) {
	visited[u]=1;
	++cnt;
	for (int v = 0; v < adj[u].size(); ++v) {
		if (!visited[adj[u][v]]) {
			dfs(adj[u][v]);
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
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
  	if (!visited[i]) {
  		cnt = 0;
  		dfs(i);
  		// cout << cnt << endl;
  		ans+=cnt*(cnt-1)/2;
  	}
  }
  cout << ans << endl;
  return 0;
}