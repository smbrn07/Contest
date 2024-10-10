#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int nmax = 1e5 + 7;
ll a[nmax];
int n, k;
bool check(ll x) {
  ll sum = 0;
  int cnt = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (sum + a[i] <= x) {
      sum += a[i];
    } else {
      sum = a[i];
      ++cnt;
    }
  }
  return (cnt <= k);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  ll n_max = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    n_max = max(n_max, a[i]);
  }
  a[n + 1] = 1e18 + 7;
  ll l = n_max, r = 1e18 + 7;
  ll ans;
  while (l <= r) {
    ll x = (l + r) / 2;
    if (check(x)) {
      ans = x;
      r = x - 1;
    } else
      l = x + 1;
  }
  cout << ans;
  return 0;
}
