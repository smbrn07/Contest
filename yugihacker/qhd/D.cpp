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
const int nmax = 2e3 + 7;

int n, a[nmax], f[nmax], parent[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    f[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (a[i] > a[j] && f[j] + 1 >= f[i]) {
        parent[i] = j;
        f[i] = f[j] + 1;
      }
    }
  }
  int ans = -1, res = -1;
  for (int i = 1; i <= n; ++i) {
    if (ans < f[i]) {
      ans = f[i];
      res = i;
    }
  }
  cout << ans << endl;
  vector<int> kq;
  while (parent[res] != res) {
    kq.pb(a[res]);
    res = parent[res];
  }
  kq.pb(a[res]);
  reverse(allin(kq));
  for (int i : kq)
    cout << i << " ";
  return 0;
}
