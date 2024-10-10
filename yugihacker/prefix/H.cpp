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
const int nmax = 2e5 + 7;

int a[nmax];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   cin >> s;
   int q;
   cin >> q;
   while (q--) {
      int k;
      cin >> k;
      ++a[k];
   }
   int len = sz(s);
   s = " " + s;
   for (int i = 1; i <= len / 2; ++i) a[i] += a[i - 1];
   for (int i = 1; i <= len / 2; ++i) {
      if (a[i] & 1) swap(s[i], s[len - i + 1]);
   }
   for (int i = 1; i <= len; ++i) cout << s[i];
   return 0;
}
