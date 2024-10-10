#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define int long long
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int x, y, z, t;
int slx, sly, slz;
int valx, valy, valz;

bool ok(int mid) {
  int ax = (mid * x > slx ? mid * x - slx : 0);
  int ay = (mid * y > sly ? mid * y - sly : 0);
  int az = (mid * z > slz ? mid * z - slz : 0);
  return valx * ax + valy * ay + valz * az <= t;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> x >> y >> z >> t;
  cin >> slx >> sly >> slz;
  cin >> valx >> valy >> valz;
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;

  return 0;
}
