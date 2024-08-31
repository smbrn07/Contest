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

int P[nmax];

void sang() {
   for (int i = 1; i <= nmax; ++i)
      P[i] = 1;
   for (ll i = 2; i <= nmax; ++i) {
      for (ll j = i; j <= nmax; j += i)
         ++P[j];
   }
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int t;
   cin >> t;
   sang();
   for (int i = 1; i <= t; ++i) {
      int n;
      cin >> n;
      cout << P[n] << endl;
   }
   return 0;
}
