#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define endl '\n'
#define allin(a) begin(a), end(a)

const int nmax = 1e5 + 7;

int t, n, m, a[nmax], b[nmax];

ll cal1(int tt) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += tt / a[i];
  return cnt;
}

ll cal2(int tt) {
  ll cnt = 0;
  for (int i = 0; i < m; ++i)
    cnt += (t - tt) / b[i];
  return cnt;
}

bool ok(int tt) {
  ll cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += tt / a[i];
  for (int i = 0; i < m; ++i)
    cnt -= (t - tt) / b[i];
  return cnt <= 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> b[i];
  int l = 0, r = t;
  ll kq = 0;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (cal1(mid) >= cal2(mid)) {
      kq = max(kq, cal2(mid));
      r = mid;
    } else {
      kq = max(kq, cal1(mid));
      l = mid;
    }
  }
  cout << kq << endl;
  return 0;
}
