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

bool isP[nmax];

int n;
void sang() {
   isP[1] = 1;
   for (ll i = 1; i <= n; ++i)
      isP[i] = i;
   for (ll i = 2; i <= n; ++i) {
      if (!isP[i]) {
         for (ll j = i * i; j <= n; j += i)
            isP[j] = i;
      }
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n;
   sang();
   // cout << isP[7] << endl;
   ll res = 0;
   for (int i = 2; i <= n; ++i) {
      if (!isP[i])
         res += i;
   }
   cout << res << endl;
   return 0;
}
