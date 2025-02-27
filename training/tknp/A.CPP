#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ll a, b, n;

ll gcd(int a, int b) {
  return b==0 ? a : gcd(b, a%b);
}

bool ok(ll x) {
  ll k = a*b/gcd(a, b);
  ll cnt = x/a+x/b-x/k;
  return cnt>= n;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    cin >> a >> b >> n;
    ll l = 1, r = 1e18, ans = 0;
    while (r>=l) {
      ll mid = (l+r)/2;
      if (ok(mid)) {
        ans = mid;
        r = mid-1;
      } else l = mid+1;
    }
    cout << ans << endl;
  }
  return 0;
}