#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

const double PI = acos(-1.0);

#define TWO(x) (1 << (x))
#define CONTAIN(S, x) (S & TWO(x))

int n, m, k;
int f[111][222], mark[111];
vector<pair<int, int>> ke[111];
set<pair<int, pair<int, int>>> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  scanf("%d", &n);
  k = 4;
  FOR(i, 1, n) REP(mask, TWO(k)) f[i][mask] = 1000111000;

  FOR(i, 1, k) {
    int u;
    scanf("%d", &u);
    mark[u] = i;
    f[u][TWO(i - 1)] = 0;
    s.insert(MP(0, MP(u, TWO(i - 1))));
  }
  int u, v, c;
  while (scanf("%d%d%d", &u, &v, &c) == 3) {
    ke[u].PB(MP(v, c));
    ke[v].PB(MP(u, c));
  }
  while (!s.empty()) {
    int l = s.begin()->F;
    pair<int, int> now = s.begin()->S;
    int u = now.F, mask = now.S;

    if (now.S == TWO(k) - 1) {
      printf("%d\n", l);
      return 0;
    }
    s.erase(s.begin());

    REP(i, ke[u].size()) {
      int v = ke[u][i].F, c = ke[u][i].S;
      int mask2 = now.S;
      if (mark[v])
        mask2 |= TWO(mark[v] - 1);

      int cost = f[u][mask] + c;
      if (f[v][mask2] > cost) {
        f[v][mask2] = cost;
        s.insert(MP(f[v][mask2], MP(v, mask2)));
      }

      REP(mask3, TWO(k)) if ((mask3 & mask) == 0) {
        int cost = f[u][mask] + f[v][mask3] + c;
        if (f[v][mask3 | mask] > cost) {
          f[v][mask3 | mask] = cost;
          s.insert(MP(cost, MP(v, mask3 | mask)));
        }
      }
    }
  }
  return 0;
}
