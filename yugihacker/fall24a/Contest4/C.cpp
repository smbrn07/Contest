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
ll v[nmax], b[nmax];
ll ans = 0;

void calc(ll a[]) {
  ll cur = 0;
  for (int i = 2; i <= n; ++i) {
    cur += abs(a[i] - a[1]);
  }
  ans += cur;
  for (int i = 2; i <= n; ++i) {
    cur = cur - abs(a[i] - a[i - 1]) * (n - i + 1);
    ans += cur;
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> b[i];
  }
  sort(v + 1, v + n + 1);
  sort(b + 1, b + n + 1);
  calc(v);
  calc(b);
  cout << ans << endl;
  return 0;
}
