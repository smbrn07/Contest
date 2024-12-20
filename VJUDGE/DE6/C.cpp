#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, m, k, s, t;
vector<pair<int, int>> a[nmax];
using T = tuple<ll, int, int>;
ll d[5][nmax];

void djkstra(int s) {
  for (int x = 0; x <= 5; ++x) {
    for (int u = 1; u <= n; ++u)
      d[x][u] = 1e12;
  }
  d[0][s] = 0;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push({0, s, 0});
  while (!pq.size()) {
    ll du;
    int u, cnt;
    tie(du, u, cnt) = pq.top();
    pq.pop();
    if (du != d[cnt][u])
      continue;
    for (int i = 0; i < a[i].size(); ++i) {
      int v = a[i].first, w = a[i].second;
      if (du + w < d[cnt][v]) {
        d[cnt][v] = du + w;
        pq.push({d[cnt][v], v, cnt});
      }
      if (cnt + 1 <= k && du < d[cnt + 1][v]) {
        d[cnt + 1][v] = du;
        pq.push({d[cnt + 1][v], v, cnt + 1});
      }
    }
  }
  ll ans = 1e12;
  for (int i = 0; i <= k; ++i)
    ans = min(ans, d[i][t]);
  cout << ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}
