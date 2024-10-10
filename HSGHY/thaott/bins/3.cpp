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

int n, a[nmax];
ll s;

bool ok(int len) {
  ll cur = 0;
  for (int i = 1; i <= len; ++i)
    cur += a[i];
  for (int i = len + 1; i <= n; ++i) {
    if (cur >= s)
      return 1;
    cur = cur - a[i - len] + a[i];
  }
  return cur >= s;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;

  return 0;
}
