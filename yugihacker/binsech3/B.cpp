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

int n, tt, t, x;
int a[nmax];

int search1(int x) {
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= x)
      l = mid;
    else
      r = mid;
  }
  if (l >= 0)
    return a[l];
  return -1;
}

int search2(int x) {
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] < x)
      l = mid;
    r = mid;
  }
  if (l >= 0)
    return a[l];
  return -1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> tt;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  while (tt--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      int pos = lower_bound(a, a + n, x) - a;
      if (pos < n)
        cout << a[pos] << endl;
      else
        cout << -1 << endl;
    } else if (t == 2) {
      int pos = upper_bound(a, a + n, x) - a;
      if (pos < n)
        cout << a[pos] << endl;
      else
        cout << -1 << endl;
    } else if (t == 3) {
      cout << search1(x) << endl;
    } else if (t == 4)
      cout << search2(x) << endl;
    else {
      bool flag = binary_search(a, a + n, x);
      if (!flag)
        cout << 0 << endl;
      else {
        int pos1 = lower_bound(a, a + n, x) - a;
        int pos2 = upper_bound(a, a + n, x) - a;
        cout << pos2 - pos1 << endl;
      }
    }
  }
  return 0;
}
