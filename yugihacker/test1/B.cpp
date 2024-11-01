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

int n, a[nmax], ls[nmax];
ll pref[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("EXLIST.INP", "r", stdin);
  freopen("EXLIST.OUT", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    ls[a[i]] = i;
  }
  int len = 0;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (ls[a[i]] - i + 1 == len) {
      if (pref[ls[a[i]]] - pref[i - 1] > ans) {
        ans = pref[ls[a[i]]] - pref[i - 1];
      }
    } else if (ls[a[i]] - i + 1 > len) {
      len = ls[a[i]] - i + 1;
      ans = pref[ls[a[i]]] - pref[i - 1];
    }
  }
  cout << len << " " << ans << endl;
  return 0;
}
