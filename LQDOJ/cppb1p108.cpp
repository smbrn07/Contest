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

ll binpow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binpow(a, b / 2);
  res = res * res;
  if (b & 1)
    res = res * a;
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  cout << binpow(a, b);

  return 0;
}
