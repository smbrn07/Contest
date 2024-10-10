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
const int nmax = 1e6;

int n, f[nmax + 7];
bool p[nmax + 7];
vector<int> v;

void sieve(int x) {
  for (int i = 2; i <= x; ++i) {
    if (p[i] == 0) {
      v.pb(i);
      for (ll j = 1ll * i * i; j <= x; j += i)
        p[j] = 1;
    }
  }
}

int xuli(int x) {
  int res = 1, len = sz(v);
  for (int i = 0; i < len; ++i) {
    int pow = 0;
    while (x % v[i] == 0) {
      x /= v[i];
      ++pow;
    }
    if (pow & 1)
      res *= v[i];
    if (x == 1 || v[i] > x)
      break;
  }
  if (x > 1)
    return res * x;
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  sieve(sqrt(nmax));
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    int res = xuli(x);
    ans += f[res];
    ++f[res];
  }
  cout << ans << endl;
  return 0;
}
