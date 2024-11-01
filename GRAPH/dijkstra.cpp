#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e6 + 7;
const ll INF = 2e18;

int n, m;
ll d[nmax];
vector<pii> adj[nmax];
// bool visited[nmax];

void dijkstra(int s) {
  for (int i = 1; i <= n; ++i)
    d[i] = INF;
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    pii i = q.top();
    q.pop();
    int u = i.second, dis = i.first;
    if (dis > d[u])
      continue;
    for (auto j : adj[u]) {
      int v = j.first, w = j.second;
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
  }
  dijkstra(1);
  for (int i = 1; i <= n; ++i)
    cout << d[i] << " ";
  return 0;
}
