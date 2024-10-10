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

struct edge {
   int u, v, w;
};

int n, m;
vector<edge> adj, mst;
int parent[nmax], ord[nmax];

void make_set() {
   for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      ord[i] = 1;
   }
}

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

bool Union(int u, int v) {
   u = find(u), v = find(v);
   if (u == v)
      return 0;
   if (ord[u] < ord[v])
      swap(u, v);
   parent[v] = u;
   ord[u] += ord[v];
   return 1;
}

bool cmp(edge u, edge v) { return u.w < v.w; }

void kruskal() {
   int d = 0;
   sort(allin(adj), cmp);
   for (int i = 0; i < m; ++i) {
      if (sz(mst) == n - 1)
         break;
      edge j = adj[i];
      if (Union(j.u, j.v)) {
         d += j.w;
         mst.pb({j.u, j.v, j.w});
      }
   }
   cout << d << endl;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int x, y, w;
      cin >> x >> y >> w;
      edge e = {x, y, w};
      adj.pb(e);
   }
   make_set();
   kruskal();
   return 0;
}
