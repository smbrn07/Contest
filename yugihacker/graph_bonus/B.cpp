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

int n, s, t, parent[nmax];
pair<int, int> p[nmax];
vector<int> v;

int pos(int x) { return lower_bound(allin(v), x) - begin(v); }

void make_set() {
  for (int i = 1; i <= 1e5; ++i) {
    parent[i] = i;
  }
}

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

void Union(int u, int v) {
  if (u == v || u == t)
    return;
  u = find(u), v = find(v);
  if (u != t)
    parent[u] = v;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s >> t;
  make_set();
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i].ff >> p[i].ss;
    v.pb(p[i].ff), v.pb(p[i].ss);
  }
  sort(allin(v));
  s = pos(s), t = pos(t);
  for (int i = 1; i <= n; ++i) {
    p[i].ff = pos(p[i].ff), p[i].ss = pos(p[i].ss);
  }
  for (int i = 1; i <= n; ++i) {
    Union(find(p[i].ff), p[i].ss);
    if (find(s) == t) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
