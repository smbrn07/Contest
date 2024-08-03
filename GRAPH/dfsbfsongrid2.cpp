#include <bits/stdc++.h>

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

int n, m, x1, y1, x2, y2;
char a[1007][1007];
bool visited[1007][1007];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j) {
	visited[i][j]=true;
	for (int k = 0; k < 4; ++k) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&!visited[i1][j1]&&a[i1][j1]!='x') {
			visited[i1][j1]=true;
			dfs(i1, j1);
		}
	}
}

// void bfs(int i, int j) {
// 	memset(visited, 0, sizeof(visited));
// 	queue<pair<int, int>> q;
// 	visited[i][j]=true;
// 	q.push({i, j});
// 	while (!q.empty()) {
// 		pair<int,int> v = q.front(); q.pop();
// 		for (int k = 0; k < 4; ++k) {
// 			int i1 = i + dx[k];
// 			int j1 = j + dy[k];
// 			if (i1>=1&&i1<=n&&j1>=1&&j1<=m&&!visited[i1][j1]&&a[i1][j1]=='.') {
// 				q.push({i1, j1});
// 				visited[i1][j1]=true;
// 			}
// 		}
// 	}
// }

void check() {
	dfs(x1, y1);
	cout << (visited[x2][y2] ? "YES" : "NO") << endl;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
   	for (int j = 1; j <= m; ++j) {
   		cin >> a[i][j];
   		if (a[i][j]=='A') { x1=i; y1=j; }
   		if (a[i][j]=='B') { x2=i; y2=j; }
   	}
   }
   // cout << x1 << " " << y1 << endl;
   // cout << x2 << " " << y2 << endl;
   check();
   return 0;
}