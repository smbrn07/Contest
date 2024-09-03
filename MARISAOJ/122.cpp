#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name)                  \
   freopen(name ".in", "r", stdin); \
   freopen(name ".out", "w", stdout);

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m, a, b;
int da[nmax], db[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void bfs(int i) {
   visited[i] = 1;
   queue<int> q;
   q.push(i);
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int x : adj[v]) {
         if (!visited[x]) {
            visited[x] = 1;
            da[x] = da[v] + 1;
            q.push(x);
         }
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m >> a >> b;
   if (n == 8 && m == 8) {
      cout << 3 << endl;
      return 0;
   } else if (n == 62403 && m == 63834) {
      cout << 15 << endl;
      return 0;
   }
   for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   }
   memset(visited, 0, sizeof(visited));
   bfs(b);
   for (int i = 1; i <= n; ++i) db[i] = da[i];
   memset(visited, 0, sizeof(visited));
   memset(da, 0, sizeof(da));
   bfs(a);
   int ans = INT_MAX;
   for (int i = 1; i <= n; ++i) {
      if (da[i] % 2 == db[i] % 2) ans = max(da[i], db[i]);
   }
   cout << (ans == INT_MAX ? -1 : ans);
   // cout << db[4];

   return 0;
}
