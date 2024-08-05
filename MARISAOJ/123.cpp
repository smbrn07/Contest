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
const int nmax = 1e3+7;

int n, m;
char a[nmax][nmax];
int cnt = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j) {
	if (a[i][j]=='x') ++cnt;
	a[i][j]='#';
	for (int k = 0; k < 4; ++k) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1>=1&&i1<=n&&j1<=m&&j1>=1&&a[i1][j1]!='#') {
			if (a[i1][j1]=='x') ++cnt;
			a[i1][j1]='#';
			dfs(i1, j1);
		}
	}
}

void connectedcomponent() {
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j]!='#') {
				cnt = 0;
				dfs(i, j);
				ans.pb(cnt);
			}
		}
	}
	sort(allin(ans));
	for (int i : ans) if (i!=0) cout << i << " ";
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
   	for (int j = 1; j <= m; ++j) cin >> a[i][j];
   }
	connectedcomponent();
   return 0;
}