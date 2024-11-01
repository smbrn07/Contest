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

string s;
int n, d[nmax], k[nmax];
bool visited[nmax];
vector<int> adj[nmax];

void bfs(int i) {
  if (s[1] == '0')
    ++d[1];
  else
    ++k[1];
  visited[i] = 1;
  queue<int> q;
  q.push(i);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (!visited[u]) {
        visited[u] = 1;
        d[u] += (s[u] == '0' ? d[v] + 1 : d[v]);
        k[u] += (s[u] == '1' ? k[v] + 1 : k[v]);
        q.push(u);
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  s = " " + s;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  bfs(1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > k[i]) {
      ++cnt;
    }
  }
  cout << cnt << endl;

  return 0;
}
