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
const int nmax = 3e5 + 7;

int n;
vector<int> adj[nmax];
bool visited[nmax];
int d[nmax];

void bfs(int i) {
  queue<int> q;
  q.push(i);
  visited[i] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int x : adj[v]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = 1;
        d[x] = d[v] + 1;
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  bfs(1);
  int maxv = 0;
  for (int i = 1; i <= n; ++i) {
    maxv = max(maxv, d[i]);
  }
  cout << 3 * (maxv + 1) << endl;
  return 0;
}
