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
const int nmax = 1e6 + 8;

int f[nmax]; // so luong phan tu co uoc la i;

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      ++f[x];
   }
   for (int i = nmax; i >= 1; --i) {
      int res = 0;
      for (int j = i; j <= nmax; j += i) {
         res += f[j];
      }
      if (res > 1) {
         cout << i;
         break;
      }
   }
   return 0;
}
