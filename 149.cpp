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

int n, m, tt;
vector<int> adj[nmax];
int a1[nmax], a2[nmax], a3[nmax], col[nmax];
bool colored[nmax][11];

void dfs(int u, int d, int c) {
  if (d < 0 || colored[u][d])
    return;
  colored[u][d] = 1;
  if (col[u] == 0)
    col[u] = c;
  for (int v : adj[u])
    dfs(v, d - 1, c);
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
  cin >> tt;
  for (int i = 1; i <= tt; ++i)
    cin >> a1[i] >> a2[i] >> a3[i];
  for (int i = tt; i >= 1; --i) {
    dfs(a1[i], a2[i], a3[i]);
  }
  for (int i = 1; i <= n; ++i)
    cout << col[i] << endl;

  return 0;
}
