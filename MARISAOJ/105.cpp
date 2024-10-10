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
const int nmax = 3e5 + 7;

int n, a[nmax], f[1000007];

int xuli(int x) {
  int res = 1;
  for (int i = 2; i * i <= x; ++i) {
    int pow = 0;
    while (x % i == 0) {
      x /= i;
      ++pow;
    }
    if (pow & 1)
      res *= i;
  }
  if (x > 1)
    return res * x;
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int res = xuli(a[i]);
    ans += f[res];
    ++f[res];
  }
  cout << ans << endl;

  return 0;
}
