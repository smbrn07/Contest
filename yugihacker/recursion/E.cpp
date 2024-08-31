#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int nmax = 1e5 + 7;
ll mod;

ll mul(ll a, ll b) {
   if (b == 0)
      return 0;
   ll res = mul(a, b / 2) % mod;
   res = (res + res) % mod;
   if (b & 1)
      res = res + a % mod;
   return res % mod;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   ll a, b;
   cin >> a >> b >> mod;
   cout << mul(a, b) << endl;

   return 0;
}
