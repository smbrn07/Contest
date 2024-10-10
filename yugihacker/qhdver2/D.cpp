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

int a[107], n, s;
bool dp[1007];
int tv[1007];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= s; ++i)
    tv[i] = 1e9;
  dp[0] = 1;
  tv[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = s; j >= a[i]; --j) {
      if (dp[j - a[i]] == 1) {
        dp[j] = 1;
        tv[j] = min(tv[j], i);
      }
    }
  }
  if (dp[s]) {
    vector<int> v;
    while (s != 0) {
      v.pb(tv[s]);
      s -= a[tv[s]];
    }
    cout << v.size() << endl;
    for (int i : v)
      cout << i << " ";
  } else
    cout << -1 << endl;
  return 0;
}
