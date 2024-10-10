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
   string s;
   cin >> s;
   map<char, int> mp;
   for (char i : s) {
      ++mp[i];
   }
   for (char i = 'a'; i <= 'z'; ++i) {
      if (mp[i] > 0)
         cout << i << " " << mp[i] << endl;
   }

   return 0;
}
