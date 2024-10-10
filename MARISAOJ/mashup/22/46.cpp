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

bool ok(string s) {
   int len = sz(s) - 1;
   for (int i = 1; i <= len / 2; ++i) {
      if (s[i] != s[len - i + 1])
         return 0;
   }
   return 1;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   cin >> s;
   s = " " + s;
   cout << (ok(s) ? "YES" : "NO") << endl;

   return 0;
}
