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

vector<int> adj[nmax];
int parent[nmax], d[nmax], f[nmax], x;
bool visited[nmax];

void bfs(int u) {
  visited[u] = 1;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int x : adj[v]) {
      if (!visited[x]) {
        visited[x] = 1;
        d[x] = d[v] + 1;
        q.push(x);
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  for (int i = 1; i <= n; ++i)
    f[i] = 1;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p.pb({x, y});
    adj[x].pb(y), adj[y].pb(x);
  }
  bfs(1);
  for (pair<int, int> i : p) {
    int x = i.first, y = i.second;
    // cout << d[x] << " " << d[y] << endl;
    if (d[x] < d[y])
      parent[y] = x;
    else
      parent[x] = y;
  }
  vector<pair<int, int>> l;
  for (int i = 2; i <= n; ++i) {
    l.pb({d[i], i});
  }
  sort(allin(l));
  reverse(allin(l));
  for (pair<int, int> i : l) {
    f[parent[i.second]] += f[i.second];
  }
  for (int i = 1; i <= n; ++i)
    cout << f[i] << " ";

  return 0;
}
