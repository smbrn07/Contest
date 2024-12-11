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

int n, k;
map<string, int> mp;
ll dp[1007];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    sort(allin(s));
    // cout << s << endl;
    ++mp[s];
  }
  vector<int> v;
  for (auto i : mp) {
    v.pb(i.ss * (i.ss - 1) / 2);
  }
  sort(allin(v));
  // for (int i : v)
  // cout << i << endl;
  for (int i : v) {
    ++dp[0];
    for (int j = k; j >= 0; --j) {
      for (int m = i; m > 0; --m) {
        if (j - m >= 0) {
          (dp[j] += dp[j - m]) %= mod;
        }
      }
    }
  }
  cout << dp[k] << endl;
  return 0;
}
