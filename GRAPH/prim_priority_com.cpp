#include "bits/stdc++.h"
#include <queue>

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

struct edge {
   int u, v, w;
};

int n, m;
vector<pii> adj[nmax];
bool visited[nmax];
int parent[nmax], d[nmax];

void prim(int u) {
   priority_queue<pii, vector<pii>, greater<pii>> pq;
   int cost = 0;
   vector<edge> mst;
   pq.push({0, u});

   while (!pq.empty()) {
      pii i = pq.top();
      pq.pop();
      int x = i.ss, w = i.ff;

      if (visited[x])
         continue;
      cost += w;
      visited[x] = 1;
      if (x != u) {
         mst.pb({x, parent[x], w});
      }
      for (auto it : adj[x]) {
         int y = it.ff, W = it.ss;
         if (!visited[y] && W < d[y]) {
            pq.push({W, y});
            d[y] = W;
            parent[y] = x;
         }
      }
   }
   cout << cost << endl;
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
   for (int i = 1; i <= n; ++i)
      d[i] = INT_MAX;
   prim(1);
   return 0;
}
