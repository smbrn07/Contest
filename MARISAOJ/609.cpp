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

bool ok(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return 0;
  }
  return x > 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int c = 10;
  for (int i = 1; i <= c; ++i) {
    for (int j = 1; j <= c; ++j) {
      for (int k = 1; k <= c; ++k) {
        if (i < j && j < k) {
          if (ok(i + j) && ok(i + k) && ok(j + k))
            cout << i << " " << j << " " << k << endl;
          else if (!ok(i + j) && !ok(i + k) && !ok(j + k))
            cout << i << " " << j << " " << k << endl;
        }
      }
    }
  }
  return 0;
}
