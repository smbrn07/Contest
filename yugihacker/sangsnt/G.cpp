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

ll n, p;
map<ll, ll> mp;

bool ok(ll mid) {
   for (auto i : mp) {
      int mu = i.ss * mid;
      int cur = i.ff;
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> p;
   for (ll i = 2; i <= n; ++i) {
      if (n % i == 0) {
         ll cnt = 0;
         while (n % i == 0) {
            n /= i;
            ++cnt;
         }
         mp[i] = cnt;
      }
   }
   // for (auto i : mp) cout << i.ff << " " << i.ss << endl;
   ll l = 0, r = 1e9;
   while (l <= r) {
      ll mid = (l + r) / 2;
   }
   return 0;
}
