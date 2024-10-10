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

bool dp[2007][2007];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = sz(s);
  s = " " + s;
  for (int i = 1; i <= n; ++i)
    dp[i][i] = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i + 1])
      dp[i][i + 1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    int l = i, r = i;
    while (l - 1 > 0 && r + 1 <= n && dp[l][r] && s[l - 1] == s[r + 1]) {
      dp[l - 1][r + 1] = 1;
      --l, ++r;
    }
  }
  for (int i = 1; i < n; ++i) {
    int l = i, r = i + 1;
    while (l - 1 > 0 && r + 1 <= n && dp[l][r] && s[l - 1] == s[r + 1]) {
      dp[l - 1][r + 1] = 1;
      --l, ++r;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (dp[l][r] ? "YES" : "NO") << endl;
  }
  return 0;
}
