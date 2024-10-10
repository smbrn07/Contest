#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll f[100];

void ktao() {
  f[0] = (ll)1;
  f[1] = (ll)1;
  for (int i = 2; i <= 93; ++i)
    f[i] = f[i - 1] + f[i - 2];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ktao();
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    cout << f[x] << endl;
  }
  return 0;
}
