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

ll kq(ll n, ll d) {
   ll s = 0;
   for (int i = n; i > 0; i /= d) {
      s += i / d;
   }
   return s;
}

ll n, p;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> p;
   ll s = INT_MAX;
   for (int i = 2; i <= p; i++) {
      if (p % i == 0) {
         int d = 0;
         while (p % i == 0) {
            p /= i;
            d++;
         }
         s = min(s, kq(n, i) / d);
      }
   }
   cout << s;
   return 0;
}
