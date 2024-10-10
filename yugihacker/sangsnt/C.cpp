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

ll pow5[15];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   pow5[0] = 1;
   for (int i = 1; i <= 14; ++i) {
      pow5[i] = pow5[i - 1] * 5;
   }
   ll n;
   cin >> n;
   ll cnt = 0;
   for (int i = 1; i <= 14; ++i) {
      if (n >= pow5[i])
         cnt += n / pow5[i];
      else
         break;
   }
   cout << cnt << endl;
   return 0;
}
