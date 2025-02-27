#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back

const int mod = 1e9 + 7;
const int nmax = 1e3 + 7;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m;
char a[nmax][nmax];

void dfs(int i, int j) {
	a[i][j]='#';
	for (int k = 0; k < 4; ++k) {
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if (i1>=1 && j1>=1 && i1<=n && j1<=m && a[i1][j1]=='.') {
			dfs(i1, j1);
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
  	for (int j = 1; j <= m; ++j) {
  		cin >> a[i][j];
  	}
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
  	for (int j = 1; j <= m; ++j) {
  		if (a[i][j]=='.') {
  			++cnt;
  			dfs(i, j);
  		}
  	}
  }
  cout << cnt;
  return 0;
}