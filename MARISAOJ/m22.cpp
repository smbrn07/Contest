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

int a[nmax];
map<int, int> mp;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] %= 23;
  }
  ll ans = 0;
  for (int i = 6; i <= n; ++i) {
    ans += mp[a[i]];
    ++mp[a[i - 5]];
  }
  cout << ans << endl;

  return 0;
}
