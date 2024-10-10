#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
char a[1007][1007];
bool visited[1007][1007];

void dfs(int i, int j) {
  visited[i][j] = 1;
  for (int k = 0; k <= 4; ++k) {
    int i1 = i + dx[k], j1 = j + dy[k];
    if (a[i1][j1] == '.' && !visited[i1][j1] && i1 >= 1 && i1 <= n && j1 >= 1 &&
        j1 <= m) {
      visited[i1][j1] = 1;
      dfs(i1, j1);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = ch;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!visited[i][j] && a[i][j] == '.') {
        dfs(i, j);
        ++ans;
      }
    }
  }
  cout << ans;
  return 0;
}
