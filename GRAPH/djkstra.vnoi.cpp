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
const ll INF = 2e18;
const int nmax = 1e5 + 7;

struct Edge {
  int v;
  ll w;
};

struct Node {
  int u;
  ll Dist_u;
};

struct cmp {
  bool operator()(Node a, Node b) { return a.Dist_u > b.Dist_u; }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  return 0;
}
