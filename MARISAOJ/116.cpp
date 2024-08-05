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
const int nmax = 1e5+7;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);

   int n, m;
  	cin >> n >> m;
	vector<int> adj[n+1];
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y);
   	adj[y].pb(x);
   }

	bool visited[n+1];
	int d[n+1];

	memset(visited, 0, sizeof(visited));
	memset(d, 0, sizeof(d));

   queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				d[x]=d[v]+1;
				visited[x]=true;
				q.push(x);
			}
		}
	}

   for (int i = 2; i <= n; ++i) {
   	cout << (d[i]>0 ? d[i] : -1) << " ";
   }
   return 0;
}