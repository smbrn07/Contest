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

ll val[5][3][2];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  val[3][1][0] = 600;
  val[3][2][0] = 800;
  val[3][1][1] = 500;
  val[3][2][1] = 700;
  val[4][1][0] = 300;
  val[4][2][0] = 400;
  val[4][1][1] = 250;
  val[4][2][1] = 350;
  int l, m;
  ll n;
  cin >> l >> m >> n;
  bool p = n >= (ll)100;
  cout << 1ll * n * val[l][m][p];
  return 0;
}
