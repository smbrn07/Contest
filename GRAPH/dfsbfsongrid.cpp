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

int n, m;
char a[1007][1007];
bool visited[1007][1007];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j) {
	visited[i][j]=true;
	for (int k = 0; k < 4; ++k) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]=='.'&&!visited[i1][j1]) {
			visited[i1][j1]=true;
			dfs(i1, j1);
		}
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({i, j});
	while (!q.empty()) {
		pair<int,int> v = q.front(); q.pop();
		for (int k = 0; k < 4; ++k) {
			int i1 = v.ff + dx[k];
			int j1 = v.ss + dy[k];
			if (i1>=1&&j1>=1&&j1<=m&&i1<=n&&!visited[i1][j1]&&a[i1][j1]=='.') {
				visited[i1][j1]=true;
				q.push({i1, j1});
			}
		}
	}
}

void connectedcomponent() {
	memset(visited, 0, sizeof(visited));
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!visited[i][j]&&a[i][j]=='.') {
				bfs(i, j);
				++cnt;
			}
		}
	}
	cout << cnt << endl;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
   	for (int j = 1; j <= m; ++j) {
   		cin >> a[i][j];
   	}
   }
   connectedcomponent();
   return 0;
}