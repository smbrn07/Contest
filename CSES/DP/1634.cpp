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
const int nmax = 1e6 + 7;

int n, x, c[nmax], f[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  for (int i = 1; i <= x; ++i)
    f[i] = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (j >= c[i] && f[j - c[i]] != INT_MAX)
        f[j] = min(f[j], f[j - c[i]] + 1);
    }
  }
  cout << (f[x] == INT_MAX ? -1 : f[x]) << endl;
  return 0;
}
