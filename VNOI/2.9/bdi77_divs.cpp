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

int uoc[nmax], boso[nmax];
bool isP[nmax];

void sang() {
   for (int i = 2; i <= nmax; ++i) {
      if (!isP[i]) {
         for (ll j = 1ll * i * i; j <= nmax; j += i) isP[j] = 1;
      }
   }
   for (int i = 1; i <= nmax; ++i) {
      if (!isP[i]) {
         for (int j = i; j <= nmax; j += i) ++uoc[j];
      } else {
         for (int j = i; j <= nmax; j += i) ++boso[j];
      }
   }
}

ll f[nmax];
ll ans[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   sang();
   for (int i = 1; i <= nmax; ++i) {
      f[i] = (boso[i] * uoc[i] - uoc[i] + 1) + uoc[i] * (uoc[i] - 1) + 1;
   }
   for (int i = 1; i <= nmax; ++i) {
      ans[i] = ans[i - 1] + f[i];
   }
   cout << ans[9] << endl;

   return 0;
}
