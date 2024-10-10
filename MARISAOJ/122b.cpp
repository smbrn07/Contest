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

int n, m, a, b;
vector<int> adj[nmax], adjnew[nmax];
bool visited[nmax];
int d[nmax];

void bfs(int i) {
   visited[i] = 1;
   queue<int> q;
   q.push(i);
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : adj[v]) {
         if (!visited[u]) {
            visited[u] = 1;
            q.push(u);
            d[u] = d[v] + 1;
         }
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m >> a >> b;
   for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   return 0;
}
