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

int n, k, a[nmax];
int p[nmax], uoc[nmax], pref[nmax];

void sieve() {
  for (int i = 1; i <= nmax; ++i)
    p[i] = i;
  for (int i = 2; i <= nmax; ++i) {
    if (p[i] == i) {
      for (ll j = 1ll * i * i; j <= nmax; j += i)
        p[j] = min(p[j], i);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int cnt = 0;
  sieve();
  for (int i = 1; i <= k; ++i) {
    ++uoc[p[i]];
  }
  for (int i = 1; i <= n; ++i) {
    cout << uoc[a[i]] << endl;
  }
  return 0;
}
