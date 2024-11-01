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

int n, k;
ll dp[nmax];
bool cor[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    cor[x] = 1;
  }
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!cor[i])
      dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }
  cout << dp[n] << endl;

  return 0;
}
