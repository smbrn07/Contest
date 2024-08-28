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

int n, m;
vector<int> adj[nmax], tadj[nmax];
bool visited[nmax];
vector<int> tp;
int cnt = 0;

void dfs1(int u) {
   visited[u] = 1;
   for (int v : adj[u]) {
      if (!visited[v]) {
         visited[v] = 1;
         dfs1(v);
      }
   }
   tp.pb(u);
}

void dfs2(int u) {
   visited[u] = 1;
   cout << u << " ";
   for (int v : tadj[u]) {
      if (!visited[v]) {
         visited[v] = 1;
         dfs2(v);
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      tadj[y].pb(x);
   }
   for (int i = 1; i <= n; ++i) {
      if (!visited[i])
         dfs1(i);
   }
   memset(visited, 0, sizeof(visited));
   reverse(allin(tp));
   for (int i : tp) {
      if (!visited[i]) {
         ++cnt;
         dfs2(i);
         cout << endl;
      }
   }

   cout << cnt << endl;

   // for (int i : tp)
   //   cout << i << " ";
   // cout << endl;
   return 0;
}
