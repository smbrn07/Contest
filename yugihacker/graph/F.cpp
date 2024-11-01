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

int n, m;
int parent[nmax], ord[nmax], val[nmax];
ll a[nmax], sum[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    ord[i] = 1;
    val[i] = a[i];
    sum[i] = a[i];
  }
}

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

void Union(int a, int b) {
  if (a == b)
    return;
  a = find(a), b = find(b);
  if (ord[a] < ord[b])
    swap(a, b);
  parent[b] = a;
  ord[a] += ord[b];
  val[a] = max(val[a], val[b]);
  sum[a] += sum[b];
}

void in(int x) { cout << ord[x] << " " << sum[x] << " " << val[x] << endl; }

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  make_set();
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    x = find(x), y = find(y);
    Union(x, y);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    in(find(x));
  }

  return 0;
}
