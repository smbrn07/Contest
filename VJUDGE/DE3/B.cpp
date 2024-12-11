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

int n, mp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("CAU2.INP", "r", stdin);
  freopen("CAU2.OUT", "w", stdout);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++mp[x];
    ans = max(ans, mp[x]);
  }
  cout << ans << endl;
  return 0;
}
