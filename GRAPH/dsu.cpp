#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n;
int parent[nmax], ord[nmax];

void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    ord[i] = 1;
  }
}

// path compression
int find(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find(parent[v]);
}

// heuristic
void Union(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) {
    if (ord[a] < ord[b]) {
      swap(a, b);
      parent[b] = a;
      ord[a] += ord[b];
    }
  }
}

// dsu rand
void join(int u, int v) {
  u = find(u), v = find(v);
  if (rand() & 1)
    parent[u] = v;
  else
    parent[v] = u;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return 0;
}
