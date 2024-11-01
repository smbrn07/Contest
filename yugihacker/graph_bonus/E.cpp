#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define pil pair<int, long long>
#define pli pair<long long, int>
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 3e5 + 7;
const ll INF = 1e18;

int n, m;
vector<pil> adj[nmax];
vector<int> v;
ll d[2][nmax], dp[2][nmax];

void dijkstra(int t, int s) {
  for (int i = 1; i <= n; ++i)
    d[t][i] = INF;
  d[t][s] = 0;
  dp[t][s] = 1;
  priority_queue<pli, vector<pli>, greater<pli>> q;
  q.push({d[t][s], s});
  while (!q.empty()) {
    int u = q.top().second;
    ll du = q.top().first;
    q.pop();
    if (du > d[t][u])
      continue;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first;
      ll w = adj[u][i].second;
      if (d[t][u] + w < d[t][v]) {
        d[t][v] = d[t][u] + w;
        dp[t][v] = dp[t][u];
        q.push({d[t][v], v});
      } else {
        if (d[t][v] == d[t][u] + w)
          dp[t][v] += dp[t][u];
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
    adj[y].pb({x, w});
  }
  dijkstra(0, 1), dijkstra(1, n);
  vector<int> v;
  for (int i = 2; i < n; ++i) {
    if (d[0][i] + d[1][i] > d[0][n])
      v.pb(i);
    if (d[0][i] + d[1][i] == d[0][n]) {
      if (dp[0][i] * dp[1][i] < dp[0][n])
        v.pb(i);
    }
  }
  if (n > 2) {
    cout << v.size() << endl;
    for (int i : v)
      cout << i << endl;
  }
  return 0;
}
