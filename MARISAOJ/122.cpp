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

int n, m, marisa, reimu;
vector<int> adj[nmax];
bool visitedmarisa[nmax], visitedreimu[nmax];
int dreimu[nmax], dmarisa[nmax];

void bfsreimu(int u) {
	queue<int> q; q.push(u);
	visitedreimu[u]=1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visitedreimu[x]) {
				dreimu[x]=dreimu[v]+1;
				visitedreimu[x]=1;
				q.push(x);
			}
		}
	}
}

void bfsmarisa(int u) {
	queue<int> q; q.push(u);
	visitedmarisa[u]=1;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visitedmarisa[x]) {
				dmarisa[x]=dmarisa[v]+1;
				visitedmarisa[x]=1;
				q.push(x);
			}
		}
	}
}

void connectedcomponent() {
	bfsreimu(reimu);
	bfsmarisa(marisa);
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m >> marisa >> reimu;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y); adj[y].pb(x);
   }
   connectedcomponent();
   int ans = 1e9;
   for (int i = 1; i <= n; ++i) {
   	if (visitedreimu[i] && visitedmarisa[i]) {
   		if (dmarisa[i]==dreimu[i]) ans = min(ans, dmarisa[i]);
   		// cout << dmarisa[i]+dreimu[i] << endl;
   	}
   }
   if (ans == 1e9) cout << -1 << endl;
   else cout << ans << endl;
   return 0;
}