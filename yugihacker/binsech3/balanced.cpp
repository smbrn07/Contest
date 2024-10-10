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

ll n, a[nmax], b[nmax], c[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  ll avg = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    avg += a[i];
  }
  avg /= n;
  for (int i = 0; i < n; ++i) {
    b[i] = a[i] - avg;
    c[i] = c[i - 1] + b[i];
  }
  // for (int i = 0; i < n; ++i)
  //   cout << c[i] << " ";

  return 0;
}
