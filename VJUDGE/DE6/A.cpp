#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int f[1007];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, ans = 0;
  memset(f, 0, sizeof(f));
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++f[x];
  }
  cin >> m;
  bool flag = 0;
  while (m--) {
    int k;
    cin >> k;
    flag = 0;
    for (int i = 1; i <= k; ++i) {
      int x;
      cin >> x;
      if (f[x] > 0) {
        flag = 1;
      }
    }
    if (!flag)
      ++ans;
  }
  cout << ans << endl;
  return 0;
}
