#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e3 + 7;

// MST: Minimum spanning tree

struct edge {
   int u, v;
   int w;
};

int n, m;
vector<edge> lst;
int parent[nmax], ord[nmax];

void make_set() {
   for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      ord[i] = 1;
   }
}

int find(int u) {
   if (u == parent[u])
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
   make_set();
   vector<edge> mst;
   int d = 0;
   sort(allin(lst), cmp);
   for (int i = 0; i < m; ++i) {
      if (mst.size() == n - 1)
         break;
      edge e = lst[i];
      if (Union(e.u, e.v)) {
         mst.pb(e);
         d += e.w;
      }
   }
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
      lst.pb(e);
   }
   kruskal();
   return 0;
}
