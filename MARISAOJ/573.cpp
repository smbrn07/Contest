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

ll dp[nmax][30];
char c[5] = {'m', 'a', 'r', 'i', 's'};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  char ch = 'a';
  cin >> s;
  int len = sz(s);
  s = " " + s;
  for (int i = 1; i <= len; ++i) {
    for (int j = 0; j <= 26; ++j)
      dp[i][j] = dp[i - 1][j];
    if (s[i] == 'm') {
      dp[i]['m' - ch] += 1;
      dp[i]['m' - ch] %= mod;
    } else if (s[i] == 'a') {
      dp[i]['a' - ch] += dp[i - 1]['m' - ch];
      dp[i]['a' - ch] %= mod;
    } else if (s[i] == 'r') {
      dp[i]['r' - ch] += dp[i - 1]['a' - ch];
      dp[i]['r' - ch] %= mod;
    } else if (s[i] == 'i') {
      dp[i]['i' - ch] += dp[i - 1]['r' - ch];
      dp[i]['i' - ch] %= mod;
    } else if (s[i] == 's') {
      dp[i]['s' - ch] += dp[i - 1]['i' - ch];
      dp[i]['s' - ch] %= mod;
    }
  }
  ll ans = 0;
  for (int i = 6; i <= len; ++i) {
    if (s[i] == 'a') {
      ans += dp[i - 1]['s' - ch];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
