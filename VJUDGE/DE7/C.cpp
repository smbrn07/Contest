#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, k;
int a[nmax];

int tknp(int x) {
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (binary_search(a + 1, a + n + 1, 2 * k - a[i])) {
      cout << i << ' ' << tknp(2 * k - a[i]);
      return 0;
    }
  }
  cout << "0 0";
  return 0;
}
