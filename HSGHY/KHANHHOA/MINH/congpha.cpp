#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define pb push_back


const int mod = 1e9 + 7;
const int nmax = 1e6 + 7;

int n, a[nmax], uoc[nmax];
ll ans = 0;

void sieve() {
  for (int i = 1; i <= nmax; ++i) {
    for (int j = i; j <= nmax; j += i)
      ++uoc[j];
  }
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
freopen("congpha.inp", "r", stdin);
freopen("congpha.out", "w", stdout);
  sieve();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ans += 1ll * x * uoc[x];
  }
  cout << ans;
  return 0;
}
