#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define FORl(i, s, e) for (int i = s; i < e; i++)
#define FOR(i, s, e) for (int i = s; i <= e; i++)
#define pb push_back
#define allin(v) v.begin(), v.end()

#define mod 19e+7
#define PI 3.1415926535897932384626433832795

const int nmax = 1e5 + 7;

int n, m;
vector<int> adj[nmax];
bool visited[nmax], color[nmax];

void dfs(int u) {
   visited[u] = 1;
   for (int v : adj[u]) {
      if (!visited[v]) {
         visited[v] = 1;
         color[v] = !color[u];
         dfs(v);
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(0);
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
         dfs(i);
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j : adj[i]) {
         if (color[i] == color[j]) {
            cout << "NO" << endl;
            return 0;
         }
      }
   }
   cout << "YES" << endl;
   return 0;
}
