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

int n, s, a[107], dp[1007];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = s; j >= a[i]; --j) {
      if (dp[j - a[i]] != -1)
        dp[j] = i;
    }
  }
  if (dp[s] != -1) {
    cout << dp[10];
    // vector<int> v;
    // cout << v.size() << endl;
    // for (int i : v)
    // cout << i << " ";
  } else
    cout << -1 << endl;
  return 0;
}
