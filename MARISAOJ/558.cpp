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
const int nmax = 2e5 + 7;

ll n, a[nmax];
ll avg = 0, b[nmax], c[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    avg += a[i];
  }
  for (int i = n + 1; i <= 2 * n; ++i) {
    a[i] = a[i - n];
  }
  avg /= n;
  for (int i = 1; i <= n; ++i)
    b[i] = a[i] - avg;
  for (int i = 1; i <= n; ++i)
    c[i] = c[i - 1] + b[i];
  sort(c + 1, c + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += abs(c[i] - c[(n + 1) / 2]);
  }
  cout << ans << endl;

  return 0;
}
