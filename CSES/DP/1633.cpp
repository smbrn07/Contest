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

ll f[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (i - j >= 0) {
        f[i] += f[i - j];
        f[i] %= mod;
      }
    }
  }
  cout << f[n] << endl;
  return 0;
}
