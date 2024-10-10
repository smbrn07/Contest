#include <bits/stdc++.h>
#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define maxn 100005
using namespace std;
int n, q, a[maxn];
int Find1(int x) {
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (a[m] >= x)
      r = m;
    else
      l = m;
  }
  if (a[r] == x)
    return r;
  return -1;
}
int Find2(int x) {
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (a[m] <= x)
      l = m;
    else
      r = m;
  }
  if (a[l] == x)
    return l;
  return -1;
}
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  f1(i, n) cin >> a[i];
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      if (Find1(x) != -1)
        cout << "YES";
      else
        cout << -1;
    }
    if (t == 2)
      cout << Find1(x);
    if (t == 3)
      cout << Find2(x);
    el;
  }
}
