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

int n, m;
vector<int> adj[nmax];
bool visited[nmax];
ll ans = 0, cnt;

void dfs(int i) {
  visited[i] = 1;
  ++cnt;
  for (int u : adj[i]) {
    if (!visited[u]) {
      dfs(u);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cnt = 0;
      dfs(i);
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
