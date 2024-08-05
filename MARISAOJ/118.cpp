#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 2e5+7;

int n, m;
vector<int> adj[nmax];
bool visited[nmax];
int d[nmax];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				d[x]=d[v]+1;
				visited[x]=1;
				q.push(x);
				if (x==m) return;
			}
		}
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= 1e5; ++i) {
   	adj[i].pb(i*2); adj[i].pb(i-1);
   }
   // for (int i = 1; i <= m; ++i) {
   // 	for (int j : adj[i]) cout << j << " ";
   // 	cout << endl;
   // }
   bfs(n);
   if (!visited[m]) cout << -1 << endl;
   else cout << d[m] << endl;
   return 0;
}