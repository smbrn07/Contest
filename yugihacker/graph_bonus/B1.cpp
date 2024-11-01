#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pli pair<long long, int>
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;
const ll INF = 2e18;

int n, m, parent[nmax];
vector<pli> adj[nmax];
ll d[nmax];

void dijkstra(int s) {
  for (int i = 1; i <= n; ++i)
    d[i] = INF;
  d[s] = 0;
  priority_queue<pli, vector<pli>, greater<pli>> q;
  q.push({d[s], s});
  while (!q.empty()) {
    int u = q.top().second;
    ll du = q.top().first;
    q.pop();
    if (du > d[u])
      continue;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first;
      ll w = adj[u][i].second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        parent[v] = u;
        q.push({d[v], v});
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].pb({y, w}), adj[y].pb({x, w});
  }
  memset(parent, -1, sizeof(parent));
  dijkstra(1);
  if (d[n] == INF) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> v;
  while (parent[n] != -1) {
    v.pb(n);
    n = parent[n];
  }
  v.pb(n);
  reverse(allin(v));
  for (int i : v)
    cout << i << ' ';

  return 0;
}
