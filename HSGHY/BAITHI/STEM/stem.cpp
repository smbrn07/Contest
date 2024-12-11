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
const int nmax = 2e6 + 7;

int f[nmax];

void timuoc(int x) {
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ++f[i];
      if (i * i != x)
        ++f[x / i];
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    timuoc(x);
  }
  int ans = 0;
  for (int i = 1; i <= nmax; ++i) {
    ans = max(ans, i * f[i]);
  }
  cout << ans << endl;
  return 0;
}
