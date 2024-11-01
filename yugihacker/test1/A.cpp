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
const int nmax = 31623 + 7;

bool p[nmax];
vector<int> v;

void sieve() {
  for (int i = 2; i <= nmax; ++i) {
    if (p[i] == 0) {
      v.pb(i);
      for (ll j = 1ll * i * i; j <= nmax; j += i)
        p[j] = 1;
    }
  }
}

int demuoc(int x) {
  int cnt = 0;
  for (int i : v) {
    if (i > x)
      break;
    if (x % i == 0)
      ++cnt;
  }
  return cnt;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("PRIME.INP", "r", stdin);
  freopen("PRIME.OUT", "w", stdout);
  sieve();
  int n;
  cin >> n;
  int cur = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    int cnt = demuoc(x);
    if (cur < cnt) {
      cur = cnt;
      ans = x;
    }
  }
  cout << ans << endl;
  return 0;
}
