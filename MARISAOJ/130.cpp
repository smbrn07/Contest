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
int parent[nmax];

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> q;
   for (int i = 1; i <= n; ++i)
      parent[i] = i;
   while (q--) {
      int st, u, v;
      cin >> st >> u >> v;
      u = find(u);
      v = find(v);
      if (st == 1) {
         parent[v] = u;
      } else {
         cout << ((u == v) ? "YES" : "NO") << endl;
      }
   }
   return 0;
}
