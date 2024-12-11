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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = sz(s), m = sz(t);
  s = ' ' + s;
  int ans = 0;
  for (int i = 1; i <= min(n, m); ++i) {
    if (s.substr(n - i + 1) == t.substr(0, i))
      ans = max(ans, i);
  }
  cout << s.substr(1, n - ans) << t;
  return 0;
}
