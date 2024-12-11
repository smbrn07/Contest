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

string s;
int dp[nmax];
map<int, int> mp;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("CAU3.INP", "r", stdin);
  freopen("CAU3.OUT", "w", stdout);
  string s;
  cin >> s;
  int n = s.size();
  ++mp[0];
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i] + s[i] - '0';
    dp[i + 1] %= 3;
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += mp[(dp[i] - dp[n] + 3) % 3];
    ++mp[dp[i]];
  }
  if (dp[n] == 0)
    ++ans;
  --ans;
  cout << ans << endl;
  return 0;
}
