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

ll x, y;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("CAU1.INP", "r", stdin);
  freopen("CAU1.OUT", "w", stdout);
  cin >> x >> y;
  if (x < y)
    swap(x, y);
  ll cnt = 0;
  for (int i = 1; i <= sqrt(y); ++i) {
    if (x % i == 0 && y % i == 0) {
      ++cnt;
      if (i * i != y) {
        int tmp = y / i;
        if (x % tmp == 0 && y % tmp == 0)
          ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
