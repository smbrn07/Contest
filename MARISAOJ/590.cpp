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
const int nmax = 1e5 + 7;

int n;
int a[nmax], pref[nmax], suff[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = gcd(pref[i - 1], a[i]);
  }
  for (int i = n; i >= 1; --i)
    suff[i] = gcd(suff[i + 1], a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
  cout << ans << endl;
  return 0;
}
