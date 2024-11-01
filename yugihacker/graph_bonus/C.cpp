#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define pli pair<long long, int>
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m;
vector<pli> adj[nmax];
ll d[nmax], cnt[nmax];

void dijkstra(int s) {
  for (int i = 1; i <= n; ++i)
    d[i] = 1e18;
  d[s] = 0;
  priority_queue<pli, vector<pli>, greater<pli>> q;
  q.push({0, s});
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
        cnt[v] = cnt[u];
      } else if (d[v] == d[u] + w)
        (cnt[v] += cnt[u]) %= mod;
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
  cnt[1] = 1;
  dijkstra(1);
  cout << cnt[n] << endl;

  return 0;
}
