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

void pt(int n) {
  string s = "";
  for (int i = 2; 1ll * i * i <= n; ++i) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        ++cnt;
        n /= i;
      }
      s += "*" + to_string(i);
      if (cnt > 1)
        s += "^" + to_string(cnt);
    }
  }
  if (n > 1)
    s += "*" + to_string(n);
  cout << s.substr(1) << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    pt(n);
  }
  return 0;
}
