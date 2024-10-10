#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name)                                                             \
  freopen(name ".in", "r", stdin);                                             \
  freopen(name ".out", "w", stdout);

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m;
vector<int> adj[nmax];
bool visited[nmax];
vector<int> tp;

void dfs(int i) {
  visited[i] = 1;
  for (int x : adj[i]) {
    if (!visited[x]) {
      visited[x] = 1;
      dfs(x);
    }
  }
  tp.pb(i);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
  }
  dfs(1);
  if (sz(tp) != n)
    cout << -1;
  else
    for (int i : tp)
      cout << i << " ";
  cout << endl;
  return 0;
}
