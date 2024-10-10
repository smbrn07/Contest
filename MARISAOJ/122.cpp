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
const int nmax = 1e5 + 7;

int n, m, a, b;
vector<int> adj[nmax];
bool visited[nmax];
int da[nmax], db[nmax];

void bfs(int u) {
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int x : adj[v]) {
      if (!visited[x]) {
        visited[x] = 1;
        da[x] = da[v] + 1;
        q.push(x);
      }
    }
  }
}

bool check() {
  for (int i = 1; i <= n; ++i)
    if (!visited[i])
      return 0;
  return 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  bfs(b);
  if (!check())
    cout << -1 << endl;
  for (int i = 1; i <= n; ++i)
    db[i] = da[i];
  memset(da, 0, sizeof(da));
  bfs(a);
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    if (abs(da[i] - db[i] & 1))
      continue;
    ans = min(ans, (da[i] + db[i]) / 2);
  }
  cout << (ans != 1e9 ? ans : -1) << endl;
  return 0;
}
