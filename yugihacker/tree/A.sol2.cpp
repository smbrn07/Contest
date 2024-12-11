#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, h[maxn];
vector<int> a[maxn];
void dfs(int u, int p) {
  for (int v : a[u])
    if (v != p) {
      h[v] = h[u] + 1;
      dfs(v, u);
    }
}
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++)
    cout << h[i] << " ";
}
