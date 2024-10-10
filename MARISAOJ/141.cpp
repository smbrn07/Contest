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

int w[nmax], v[nmax], dp[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, s;
  cin >> n >> s;
  for (int i = 1; i <= n; ++i)
    cin >> w[i] >> v[i];

  for (int i = 1; i <= n; ++i) {
    for (int j = s; j >= w[i]; --j) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[s];
  return 0;
}
