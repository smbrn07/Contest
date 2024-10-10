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

int cnt[260];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   string s;
   while (cin >> s) {
      for (char i : s) {
         ++cnt[tolower(i) - 'a'];
      }
   }
   for (int i = 0; i < 26; ++i) {
      cout << cnt[i] << " ";
   }

   return 0;
}
