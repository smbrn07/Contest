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

int n, a[nmax];
bool visited[nmax];
int parent[nmax], ord[nmax];

void make_set() {
   for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      ord[i] = 1;
   }
}

int find(int u) { return ((u == parent[u]) ? u : parent[u] = find(parent[u])); }

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n;
   make_set();
   for (int i = 1; i <= n; ++i)
      cin >> a[i];
   for (int i = 1; i <= n; ++i) {
      if (parent[i] == i) {
         cout << i << " ";
      }
   }
   return 0;
}
