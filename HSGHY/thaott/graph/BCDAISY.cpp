#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m;
vector<int> adj[nmax];
bool visited[nmax];

void dfs(int u) {
  visited[u] = 1;
  for (int v : adj[u]) {
    if (!visited[v])
      dfs(v);
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i])
      cout << i << endl;
  }
  return 0;
}
