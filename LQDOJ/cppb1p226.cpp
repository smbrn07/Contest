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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v;
  v.pb(a);
  v.pb(b);
  v.pb(c);
  sort(allin(v));
  for (int i : v)
    cout << i << " ";

  return 0;
}