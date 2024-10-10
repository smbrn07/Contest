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

int n;
string s = "";

void sinh(int i) {
  if (i == n)
    cout << s << endl;
  else {
    for (char j = '0'; j <= '1'; ++j) {
      s.pb(j);
      sinh(i + 1);
      s.pop_back();
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  sinh(0);

  return 0;
}
