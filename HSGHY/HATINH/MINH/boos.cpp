#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int a[nmax], b[nmax];
pair<int, int> p[nmax];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("boos.inp", "r", stdin);
  freopen("boos.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1, greater<int>());
  vector<int> v;
  for (int i = 1; i <= m; ++i) {
    v.push_back(b[i] + a[n - m + i]);
  }
  sort(v.begin(), v.end());
  cout << v[0] << " " << v.back() - v[0];
}
