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

int n, m;
vector<int> adj[nmax];
bool visited[nmax];
int d[nmax];

void bfs(int u) {
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int x : adj[v]) {
      if (!visited[x]) {
        visited[x] = 1;
        q.push(x);
        d[x] = d[v] + 1;
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  bfs(1);
  if (n == 1)
    cout << 0 << endl;
  else
    cout << (d[n] != 0 ? d[n] + 1 : -1);

  return 0;
}
