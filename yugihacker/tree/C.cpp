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
const int nmax = 2e5 + 7;

int n, d[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void bfs(int i) {
  queue<int> q;
  q.push(i);
  visited[i] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (!visited[u]) {
        visited[u] = 1;
        q.push(u);
        d[u] = d[v] + 1;
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  bfs(1);
  memset(visited, 0, sizeof(visited));
  int maxval = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > maxval) {
      maxval = d[i];
      cur = i;
    }
  }
  memset(d, 0, sizeof(d));
  bfs(cur);
  for (int i = 1; i <= n; ++i) {
    maxval = max(maxval, d[i]);
  }
  cout << maxval << endl;
  return 0;
}

