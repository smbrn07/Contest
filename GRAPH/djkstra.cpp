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
const int nmax = 2e5 + 7;

int n, m, parent[nmax];
ll d[nmax];
vector<int> v;
vector<pii> adj[nmax];
bool visited[nmax];

struct cmp {
  bool operator()(pii a, pii b) { return a.second > b.second; }
};

void dijkstra(int s) {
  for (int i = 1; i <= n; ++i)
    d[i] = 1e18;
  d[s] = 0;
  priority_queue<pii, vector<pii>, cmp> q;
  q.push({s, 0});
  while (!q.empty()) {
    pii x = q.top();
    q.pop();
    int u = x.first;
    if (visited[u])
      continue;
    visited[u] = 1;
    for (auto e : adj[u]) {
      int v = e.first;
      ll w = e.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        q.push({v, d[v]});
        parent[v] = u;
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
  dijkstra(1);
  if (d[n] == 1e18) {
    cout << -1 << endl;
    return 0;
  }

  cout << d[n] << endl;
  while (parent[n] != 0) {
    v.pb(n);
    n = parent[n];
  }
  v.pb(n);
  reverse(allin(v));
  for (int i : v)
    cout << i << " ";
  return 0;
}
