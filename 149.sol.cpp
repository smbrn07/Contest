#include <bits/stdc++.h>

const int maxN = 100005;
const int maxD = 15;
using namespace std;

int N, M, Q, ans[maxN], V[maxN], d[maxN], c[maxN];
bool memo[maxN][maxD];
vector<int> g[maxN];

void DFS(int u, int d, int c) {
  if (d < 0 || memo[u][d])
    return;
  memo[u][d] = true;
  if (ans[u] == 0)
    ans[u] = c;
  for (int v : g[u])
    DFS(v, d - 1, c);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i)
    scanf("%d%d%d", &V[i], &d[i], &c[i]);

  for (int i = Q - 1; i >= 0; --i)
    DFS(V[i], d[i], c[i]);

  for (int u = 1; u <= N; ++u)
    printf("%d\n", ans[u]);
}
