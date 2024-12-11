#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int a[5007];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  a[n + 1] = 1e9;
  ++n;
  int nhon = 0, vuong = 0, tu = 0;
  for (int i = 1; i <= n - 2; ++i) {
    int ii, jj, kk;
    ii = jj = kk = i + 2;
    for (int j = i + 1; j <= n - 1; ++j) {
      int tmp = a[i] * a[i] + a[j] * a[j];
      ii = max(ii, j + 1);
      while (tmp > a[ii] * a[ii])
        ++ii;
      nhon += ii - j - 1;
      jj = max(jj, ii);
      while (tmp == a[jj] * a[jj])
        ++jj;
      vuong += jj - ii;
      kk = max(kk, jj);
      while (a[i] + a[j] > a[kk])
        ++kk;
      tu += kk - jj;
    }
  }
  cout << nhon << ' ' << vuong << ' ' << tu;

  return 0;
}
