#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e3 + 7;

struct edge {
   int u, v;
   int w;
};

int n, m;
vector<pii> adj[nmax];
bool visited[nmax]; // visited[i] -> tap vmst; !visited[i] -> tap vadj;

void prim(int u) {
   int d = 0;
   vector<edge> mst;
   visited[u] = 1; // Cho u vao vmst;
   while (sz(mst) < n - 1) {
      // e = (x, y): canh ngan nhat co x y thuoc 2 tap khac nhau;
      int min_w = INT_MAX;
      int x, y;
      for (int i = 1; i <= n; ++i) {
         if (visited[i]) {
            for (pii it : adj[i]) {
               int j = it.ff, w = it.ss;
               if (!visited[j] && w < min_w) {
                  min_w = w;
                  x = j, y = i;
               }
            }
         }
      }
      mst.pb({x, y, min_w});
      d += min_w;
      visited[x] = 1; // cho dinh x vao vmst;
   }
   cout << d << endl;
   for (edge e : mst) {
      cout << e.u << " " << e.v << " " << e.w << endl;
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].pb({y, w});
      adj[y].pb({x, w});
   }
   memset(visited, 0, sizeof(visited));
   prim(1);
   return 0;
}
