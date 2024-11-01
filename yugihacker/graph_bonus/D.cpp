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
const ll INF = 1e18;

int n, m;
vector<pli> adj[nmax], adjn[nmax];
ll d[nmax], d1[nmax];

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
        q.push({d[v], v});
      }
    }
  }
}
void dijkstran(int s) {
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
    for (int i = 0; i < adjn[u].size(); ++i) {
      int v = adjn[u][i].first;
      ll w = adjn[u][i].second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
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
    adj[x].pb({y, w});
    adjn[y].pb({x, w});
  }
  dijkstra(1);
  for (int i = 1; i <= n; ++i)
    d1[i] = d[i];
  dijkstran(n);
  ll ans = 2e18;
  for (int i = 1; i <= n; ++i) {
    for (pli j : adj[i]) {
      ans = min(ans, d1[i] + d[j.first] + j.second / 2);
    }
  }
  cout << ans << endl;
  return 0;
}
