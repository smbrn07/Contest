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

int n, m, k;
vector<int> adj[nmax];
bool visited[nmax];
int d[nmax], ex[nmax];

void bfs() {
  queue<int> q;
  for (int i = 1; i <= k; ++i) {
    q.push(ex[i]);
    visited[ex[i]] = 1;
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int x : adj[v]) {
      if (!visited[x]) {
        q.push(x);
        d[x] = d[v] + 1;
        visited[x] = 1;
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> ex[i];
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  bfs();
  for (int i = 1; i <= n; ++i)
    cout << d[i] << " ";

  return 0;
}

