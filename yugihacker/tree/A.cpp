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

int n, f[nmax];
vector<int> adj[nmax];

void dfs(int u, int parent) {
  for (int v : adj[u])
    if (v != parent) {
      dfs(v, u);
      f[u] += f[v] + 1;
    }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    adj[x].pb(i), adj[i].pb(x);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; ++i)
    cout << f[i] << " ";

  return 0;
}
