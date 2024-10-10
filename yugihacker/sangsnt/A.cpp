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

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   ll n;
   cin >> n;
   ll cnt = 0;
   for (ll i = 1; i <= sqrtl(n); ++i) {
      if (n % i == 0) {
         if (i * i != n)
            cnt += 2;
         else
            ++cnt;
      }
   }
   cout << cnt << endl;
   return 0;
}
