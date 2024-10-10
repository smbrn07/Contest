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

int n, m, k;
int a[nmax], b[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < m; ++i)
    cin >> b[i];
  sort(a, a + n), sort(b, b + n);
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (a[i] - b[j] > k && j < m) {
      ++j;
    }
    if (a[i] <= b[j] + k) {
      ++ans;
      ++j;
    }
  }
  cout << ans << endl;
  return 0;
}
