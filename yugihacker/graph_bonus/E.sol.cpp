#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 30001;

struct Node {
  int v, x, d;
  Node *next;
  Node() {}
  Node(int v, int x, int d) {
    this->v = v;
    this->x = x;
    this->d = d;
    this->next = NULL;
  }
};

int inf, n, m, dem;
int d[MAX], d2[MAX];
Node *ke[MAX];
int low[MAX], num[MAX], fa[MAX];
bool khop[MAX], mark[MAX], vs[MAX];

void add(Node *&p, Node *q) {
  Node *tmp = p;
  p = q;
  q->next = tmp;
}

void dfs(int i) {
  num[i] = dem++;
  low[i] = num[i];
  vs[i] = true;
  for (Node *p = ke[i]; p != NULL; p = p->next) {
    int j = p->v;
    int z = p->d;
    /*if(d[j]==d[i]+z) {
        fa[j] = i;
        dfs(j);
        low[i] <?= low[j];
    }
    else if(d[j]+z==d[i] && j!=fa[i]) {
        low[i] <?= num[j];
    }*/
    if (!mark[j])
      continue;
    if (d[j] == d[i] + z || d[i] == d[j] + z) {
      if (!vs[j]) {
        fa[j] = i;
        dfs(j);
        low[i] < ? = low[j];
      } else if (j != fa[i]) {
        low[i] < ? = num[j];
      }
    }
  }
  if (fa[i] > 0) {
    int fi = fa[i];
    if (low[i] >= num[fi])
      khop[fi] = true;
  }
}

void bfs(int st, int d[MAX]) {
  queue<int> q;
  q.push(st);
  memset(d2, 60, sizeof(d2));
  inf = d[0];
  d[st] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (Node *p = ke[u]; p != NULL; p = p->next) {
      int v = p->v;
      int z = p->d;
      if (d[v] > d[u] + z) {
        d[v] = d[u] + z;
        q.push(v);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(ke[x], new Node(y, x ^ y, z));
    add(ke[y], new Node(x, x ^ y, z));
  }
  bfs(1, d);
  bfs(n, d2);
  for (int i = 1; i <= n; ++i)
    if (d[i] + d2[i] == d[n])
      mark[i] = true;
  int res = 0;
  dfs(1);
  for (int i = 2; i < n; ++i)
    if (!khop[i] || !mark[i])
      ++res;
  printf("%d\n", res);
  for (int i = 2; i < n; ++i)
    if (!khop[i] || !mark[i])
      printf("%d\n", i);
  // system("pause");
  return 0;
}

