#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int nmax = 1e5 + 7;
ll F[25];
ll binpow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (ll i = 1; i <= 18; ++i) {
    ll res = binpow(10, i) - binpow(10, i - 1);
    res *= i;
    F[i] = F[i - 1] + res;
  }
  while (tt--) {
    ll k;
    cin >> k;
    ll nth = 0;
    for (ll i = 1; i <= 18; ++i)
      if (k - F[i] < 0) {
        k -= F[i - 1];
        nth = i;
        break;
      }
    ll pos = k % nth;
    if (pos == 0)
      pos = nth;
    ll ans = binpow(10, nth - 1) + (k - pos) / nth;
    ans /= binpow(10, nth - pos);
    cout << ans % 10 << endl;
    ;
  }
  return 0;
}
