#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, m, cnt = 1;
vector<int> adj[nmax];
bool visited[nmax];
vector<int> v;

void dfs(int u) {
  visited[u] = 1;
  for (int v = 0; v < adj[u].size(); ++v) {
    if (!visited[adj[u][v]]) {
      ++cnt;
      dfs(adj[u][v]);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("build.inp", "r", stdin);
  freopen("build.out", "w", stdout);
  cin >> n >> m;
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    if (mp[{x, y}] == 0) {
      ++mp[{x, y}];
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  dfs(1);
  int cur = cnt;
  int maxval = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cnt = 1;
      dfs(i);
      maxval = max(maxval, cnt);
    }
  }
  cout << cur + maxval;
}
