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
const int nmax = 31623 + 7;

bool p[nmax];
vector<int> v;

void sieve() {
  for (int i = 2; i <= nmax; ++i) {
    if (p[i] == 0) {
      v.pb(i);
      for (ll j = 1ll * i * i; j <= nmax; j += i)
        p[j] = 1;
    }
  }
}

int cnt(int x) {
  int ans = 1;
  int len = sz(v);
  for (int i = 0; i < sz(v); ++i) {
    int pow = 0;
    while (x % v[i] == 0) {
      x /= v[i];
      ++pow;
    }
    ans *= (pow + 1);
    if (x == 1 || v[i] > x)
      break;
  }
  if (x > 1)
    return ans * 2;
  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  sieve();
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    cout << cnt(x) << endl;
  }
  return 0;
}
