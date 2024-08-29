#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define allin(a) begin(a), end(a)
#define sz(a) int(a.size())

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

struct edge {
   int u, v;
   int w;
};

int n, m, d = 0;
vector<edge> adj, mst;
int parent[nmax], ord[nmax];

void make_set() {
   for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      ord[i] = 1;
   }
}

int find(int u) {
   if (parent[u] == u)
      return u;
   return parent[u] = find(parent[u]);
}

bool Union(int a, int b) {
   a = find(a);
   b = find(b);
   if (a == b)
      return 0;
   if (ord[a] < ord[b])
      swap(a, b);
   parent[b] = a;
   ord[a] += ord[b];
   return 1;
}

bool cmp(edge a, edge b) { return a.w < b.w; }

void kruskal() {
   for (int i = 0; i < m; ++i) {
      if (sz(mst) == n - 1)
         break;
      edge j = adj[i];
      if (Union(j.u, j.v)) {
         d += j.w;
         mst.pb(j);
      }
   }
   cout << d << endl;
   for (edge i : mst) {
      cout << i.u << " " << i.v << " " << i.w << endl;
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      edge e = {x, y, z};
      adj.pb(e);
   }
   make_set();
   sort(allin(adj), cmp);
   kruskal();
   return 0;
}
