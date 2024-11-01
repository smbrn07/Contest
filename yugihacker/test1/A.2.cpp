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

int n, p[nmax];

void sieve() {
  for (int i = 2; i <= nmax; ++i) {
    if (!p[i]) {
      for (ll j = i; j <= nmax; j += i) {
        ++p[j];
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  sieve();
  cin >> n;
  int cur = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (p[x] > cur) {
      cur = p[x];
      ans = x;
    }
  }
  cout << ans << endl;

  return 0;
}
