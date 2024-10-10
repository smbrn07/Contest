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

int demuoc(int x) {
  int ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      ++ans;
      if (i * i != x)
        ++ans;
    }
  }
  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << demuoc(x) << endl;
  }

  return 0;
}
