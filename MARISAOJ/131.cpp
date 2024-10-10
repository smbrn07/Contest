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

int n, q;
int parent[nmax], ord[nmax], res[nmax];

void make_set() {
   for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      ord[i] = 1;
      res[i] = i;
   }
}

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

void Union(int u, int v) {
   if (u == v)
      return;
   u = find(u), v = find(v);
   if (ord[u] < ord[v])
      swap(u, v);
   parent[v] = u;
   ord[u] += ord[v];
   res[u] += res[v];
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> q;
   make_set();
   while (q--) {
      int st;
      cin >> st;
      if (st == 1) {
         int u, v;
         cin >> u >> v;
         u = find(u), v = find(v);
         Union(u, v);
      } else {
         int u;
         cin >> u;
         cout << res[find(u)] << endl;
      }
   }
   return 0;
}
