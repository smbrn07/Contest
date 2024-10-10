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

int n, a[nmax], m;

bool ok(int x) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += (a[i] > x ? a[i] - x : 0);
  }
  return cnt >= m;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;

  return 0;
}
