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

int m, s, t;
pair<int, int> a[nmax];
unordered_map<int, vector<int>> mp;
unordered_map<int, bool> visited;

void dfs(int u) {
  visited[u] = 1;
  for (int v : mp[u]) {
    if (!visited[v])
      dfs(v);
  }
}

bool ok(int mid) {
  mp.clear(), visited.clear();
  for (int i = 1; i <= mid; ++i) {
    mp[a[i].ff].pb(a[i].ss);
  }
  dfs(s);
  return visited[t];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> m >> s >> t;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].ff >> a[i].ss;
  }
  int l = 0, r = m + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid;
    } else
      l = mid;
  }
  if (r <= m && r >= 1)
    cout << r << endl;
  else
    cout << -1 << endl;

  return 0;
}
