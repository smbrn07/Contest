#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int m, s, t;
pair<int, int> a[nmax];
unordered_map<int, vector<int>> adj;
unordered_map<int, bool> visited;

void dfs(int u) {
	visited[u]=1;
	for (int v = 0; v < adj[u].size(); ++v) {
		if (!visited[adj[u][v]]) dfs(adj[u][v]);
	}
}

bool ok(int mid) {
	adj.clear(), visited.clear();
	for (int i = 1; i <= mid; ++i) {
		adj[a[i].first].pb(a[i].second);
	}
	dfs(s);
	return visited[t];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int sum = 0;
  for (int i = 1; i <= 2000000; ++i) sum += sqrt(i);
  cout << sum << endl;
  return 0;
}