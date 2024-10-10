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

int n, tt;
int a[nmax], f[nmax];

int lb(int x) {
  if (x < a[1])
    return -1;
  int l = 1, r = n, ans = -1;
  while (r - l > 0) {
    int mid = (l + r) / 2;
    if (a[mid] <= x) {
      r = mid;
    } else
      l = mid;
  }
  return r;
}

int ub(int x) {
  if (x <= a[1])
    return -1;
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] < x) {
      ans = x;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> tt;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++f[a[i]];
  }
  // while (tt--) {
  //   int t, x;
  //   cin >> t >> x;
  //   if (t == 1) {
  //     if (x > a[n])
  //       cout << -1 << endl;
  //     else
  //       cout << lower_bound(a + 1, a + n + 1, x) - a << endl;
  //   } else if (t == 3) {
  //     cout << lb(x) << endl;
  //   } else if (t == 2) {
  //     if (x >= a[n])
  //       cout << -1 << endl;
  //     else
  //       cout << upper_bound(a + 1, a + n + 1, x) - a << endl;
  //   } else if (t == 4) {
  //     cout << ub(x) << endl;
  //   } else if (t == 5)
  //     cout << f[x] << endl;
  // }
  cout << lb(2);
  return 0;
}
