#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl '\n'
const int nmax = 1e5 + 7;

int n, tt, a[nmax];

int tk1(int x) {
  int l = 1, r = n;
  int ans = -1;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (a[mid] >= x) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

int tk2(int x) {
  int l = 1, r = n;
  int ans = -1;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (a[mid] > x) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

int tk3(int x) {
  int l = 1, r = n;
  int ans = -1;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (a[mid] <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}

int tk4(int x) {
  int l = 1, r = n;
  int ans = -1;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (a[mid] < x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}

void in(int pos) { cout << (pos != -1 ? a[pos] : -1) << endl; }

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> tt;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  while (tt--) {
    int t, x;
    cin >> t >> x;
    if (t == 1)
      in(tk1(x));
    else if (t == 2)
      in(tk2(x));
    else if (t == 3)
      in(tk3(x));
    else if (t == 4)
      in(tk4(x));
    else {
      if (binary_search(a + 1, a + n + 1, x) == 1)
        cout << tk3(x) - tk1(x) + 1 << endl;
      else
        cout << 0 << endl;
    }
  }

  return 0;
}
