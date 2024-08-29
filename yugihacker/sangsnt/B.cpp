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

bool check(ll n) {
   for (ll i = 2; i * i <= n; ++i) {
      if (n % i == 0)
         return 0;
   }
   return 1;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   ll n;
   cin >> n;
   ll cur = 1;
   vector<pair<ll, int>> p;
   while (cur * cur <= n) {
      ++cur;
      int cnt = 0;
      while (n % cur == 0) {
         n /= cur;
         ++cnt;
      }
      if (cnt > 0)
         p.pb({cur, cnt});
   }
   if (check(n) && n > 1)
      p.pb({n, 1});
   cout << sz(p) << endl;
   for (pair<ll, int> i : p)
      cout << i.ff << " " << i.ss << endl;
   return 0;
}
