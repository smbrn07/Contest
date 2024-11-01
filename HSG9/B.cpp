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

int n, a[nmax];
unordered_map<ll, int> mp;
ll pref[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  ll ans = 0;
  ++mp[0];
  for (int i = 1; i <= n; ++i) {
    ans += mp[pref[i]];
    ++mp[pref[i]];
  }
  cout << ans << endl;
  return 0;
}

