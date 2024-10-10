#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

ll n, a[nmax];
ll pref[nmax], prefi[nmax], suff[nmax], suffi[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = n + 1; i < 2 * n; ++i)
    a[i] = a[i - n];
  for (int i = 1; i < 2 * n; ++i) {
    pref[i] = pref[i - 1] + a[i];
    prefi[i] = prefi[i - 1] + i * a[i];
  }
  for (int i = 2 * n - 1; i >= 1; --i) {
    suff[i] = suff[i + 1] + a[i];
    suffi[i] = suffi[i + 1] + (2 * n - i + 1) * a[i];
  }

  ll ans = 1e18 + 7;
  for (ll i = 1 + n / 2; i < 2 * n - n / 2; ++i) {
    // for (int j = i-n/2; j<=i+n/2; ++j) cout << a[j] << " ";
    // cout << endl;
    ll l = suffi[i - n / 2] - suffi[i] -
           (2 * n - i + 1) * (suff[i - n / 2] - suff[i]);
    ll r = prefi[i + n / 2] - prefi[i] - i * (pref[i + n / 2] - pref[i]);
    // cout << l << ' ' << r << endl;
    ans = min(ans, l + r);
  }
  cout << ans << endl;
  return 0;
}
