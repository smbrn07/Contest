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
const int nmax = 1e6 + 7;

ll f[3][nmax];

void calc() {}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  calc();
  while (tt--) {
    int x;
    cin >> x;
    cout << f[x] << endl;
  }
  return 0;
}
