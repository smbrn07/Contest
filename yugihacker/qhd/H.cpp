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
const int nmax = 1e3 + 7;

int n, S, w[nmax], v[nmax];
ll f[1000006];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> S;
  for (int i = 1; i <= n; ++i)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = S; j >= w[i]; --j) {
      f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
  }
  cout << f[S] << endl;
  return 0;
}
