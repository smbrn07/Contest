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
const int nmax = 1e3 + 7;

struct edge {
   int u, v;
   int w;
};

int n, m;
vector<edge> lst;
vector<int> mst;
bool visited[nmax];

void make_Prim(int u) {
   mst.pb(u);
   visited[u] = 1;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      edge e = {x, y, z};
      lst.pb(e);
   }

   return 0;
}
