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

int n, m, j, t;
vector<int> adj[nmax];
bool visited[nmax];
int dj[nmax], dt[nmax];

void bfsj(int u) {
	queue<int> q; q.push(u);
	visited[u]=true;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				visited[x]=true;
				dj[x]=dj[v]+1;
				q.push(x);
			}
		}
	}
}

void bfst(int u) {
	queue<int> q; q.push(u);
	visited[u]=true;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				visited[x]=true;
				dt[x]=dt[v]+1;
				q.push(x);
			}
		}
	}
}

void calc() {
	bfst(t);
	memset(visited, 0, sizeof(visited));
	bfsj(j);
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m >> j >> t;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y); adj[y].pb(x);
   }
   calc();
   ll ans = 0;
   for (int i = 1; i <= n; ++i) {
   	if (dj[i]<=dt[i]) ++ans;
   }
   cout << ans << endl;
   return 0;
}