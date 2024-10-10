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

int c[107];
bool dp[nmax][2];

bool ok(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return 0;
  }
  return x > 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  return 0;
}
